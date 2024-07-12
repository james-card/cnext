const char *defaultSslKey =
  "-----BEGIN PRIVATE KEY-----\n"
  "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\n"
  "558E1avmdDIbkkJGaLomzki7jP0KYocY4g==\n"
  "-----END PRIVATE KEY-----";

