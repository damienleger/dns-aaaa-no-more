# dns-aaaa-no-more
The sole purpose of this project is to override the getaddrinfo() system function that takes care of DNS of resolution by enforcing AI_FAMILY.AF_INET flag to get rid off AAAA (IPv6) DNS queries.