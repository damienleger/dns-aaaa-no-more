# dns-aaaa-no-more
The sole purpose of this project is to override the getaddrinfo() system function that takes care of DNS resolution by enforcing AI_FAMILY.AF_INET flag to get rid off AAAA (IPv6) DNS queries.

## build
```
make
```

## usage
```
LD_PRELOAD=/path/to/getaddrinfo.so /path/to/myprogram
```
