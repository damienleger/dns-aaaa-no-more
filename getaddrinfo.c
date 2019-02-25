#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define __USE_GNU
#include <dlfcn.h>

#include <stdlib.h>


int
getaddrinfo(const char *node, const char *service,
	    const struct addrinfo *hints, struct addrinfo **res)
{
    const static int (*orig_getaddrinfo) (const char *, const char *,
                                          const struct addrinfo *,
                                          struct addrinfo **) = NULL;

    *(void **)(&orig_getaddrinfo) = dlsym(RTLD_NEXT, "getaddrinfo");

    if (hints != NULL) {
        const struct addrinfo new_hints = {
                                       hints->ai_flags,
                                       AF_INET,
                                       hints->ai_socktype,
                                       hints->ai_protocol,
                                       hints->ai_addrlen,
                                       hints->ai_addr,
                                       hints->ai_canonname,
                                       hints->ai_next
                                       };

        return orig_getaddrinfo(node, service, &new_hints, res);
    }
    else {
        return orig_getaddrinfo(node, service, hints, res);
    }
}
