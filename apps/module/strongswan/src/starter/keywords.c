/* C code produced by gperf version 3.0.4 */
/* Command-line: /usr/bin/gperf -m 10 -C -G -D -t  */
/* Computed positions: -k'2-3,6,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif


/*
 * Copyright (C) 2005 Andreas Steffen
 * Hochschule fuer Technik Rapperswil, Switzerland
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include <string.h>

#include "keywords.h"

struct kw_entry {
    char *name;
    kw_token_t token;
};

#define TOTAL_KEYWORDS 190
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 17
#define MIN_HASH_VALUE 16
#define MAX_HASH_VALUE 400
/* maximum key range = 385, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (str, len)
     register const char *str;
     register unsigned int len;
{
  static const unsigned short asso_values[] =
    {
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401,  27,
      171, 401,  96, 401,   8, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 153, 401,  38,  18, 110,
       79,   8,   5,  15, 114,   4, 401, 144,  62, 124,
       29,  87,  79,   8,  20,   4,  22, 127,  34, 401,
      401,  59,  23, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401, 401, 401, 401, 401,
      401, 401, 401, 401, 401, 401
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[5]];
      /*FALLTHROUGH*/
      case 5:
      case 4:
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

static const struct kw_entry wordlist[] =
  {
    {"pfs",               KW_PFS_DEPRECATED},
    {"lifetime",          KW_KEYLIFE},
    {"rightimei",         KW_RIGHTIMEI},
    {"left",              KW_LEFT},
    {"rightsourceif",     KW_RIGHTSOURCEIF},
    {"right",             KW_RIGHT},
    {"leftgroups",        KW_LEFTGROUPS},
    {"rightgroups",       KW_RIGHTGROUPS},
    {"leftcert",          KW_LEFTCERT},
    {"aggressive",        KW_AGGRESSIVE},
    {"leftdns",           KW_LEFTDNS},
    {"uniqueids",         KW_UNIQUEIDS},
    {"leftsendcert",      KW_LEFTSENDCERT},
    {"rightsubnet",       KW_RIGHTSUBNET},
    {"rightikeport",      KW_RIGHTIKEPORT},
    {"rightsendcert",     KW_RIGHTSENDCERT},
    {"rightintsubnet",    KW_RIGHTINTSUBNET},
    {"rightimeiformat",   KW_RIGHTIMEIFORMAT},
    {"rightikeportnatt",  KW_RIGHTIKEPORTNATT},
    {"lifepackets",       KW_LIFEPACKETS},
    {"rightidr_apn",      KW_RIGHTIDR_APN},
    {"certuribase",       KW_CERTURIBASE},
    {"leftprotoport",     KW_LEFTPROTOPORT},
    {"rightsubnetwithin", KW_RIGHTSUBNET},
    {"interfaces",        KW_SETUP_DEPRECATED},
    {"keep_alive",        KW_SETUP_DEPRECATED},
    {"interface",         KW_INTERFACE},
    {"retrans_tries",     KW_RETRANS_TRIES},
    {"leftintsubnet",     KW_LEFTINTSUBNET},
    {"retrans_base",      KW_RETRANS_BASE},
    {"lifebytes",         KW_LIFEBYTES},
    {"server_nocert",     KW_SERVER_NOCERT},
    {"virtual_private",   KW_SETUP_DEPRECATED},
    {"leftsigkey",        KW_LEFTSIGKEY},
    {"keylife",           KW_KEYLIFE},
    {"leftrsasigkey",     KW_LEFTSIGKEY},
    {"leftfirewall",      KW_LEFTFIREWALL},
    {"rightsigkey",       KW_RIGHTSIGKEY},
    {"leftcertpolicy",    KW_LEFTCERTPOLICY},
    {"leftca",            KW_LEFTCA},
    {"crluri",            KW_CRLURI},
    {"keyingtries",       KW_KEYINGTRIES},
    {"mark_in",           KW_MARK_IN},
    {"rightfirewall",     KW_RIGHTFIREWALL},
    {"reqid",             KW_REQID},
    {"marginbytes",       KW_MARGINBYTES},
    {"rightforcetsifull", KW_RIGHTFORCETSIFULL},
    {"marginpackets",     KW_MARGINPACKETS},
    {"margintime",        KW_REKEYMARGIN},
    {"use_cfg_vip",       KW_USE_CFG_VIP},
    {"fragmentation",     KW_FRAGMENTATION},
    {"rightid",           KW_RIGHTID},
    {"rightdns",          KW_RIGHTDNS},
    {"leftnexthop",       KW_LEFT_DEPRECATED},
    {"rightrsasigkey",    KW_RIGHTSIGKEY},
    {"rightpcscf",        KW_RIGHTPCSCF},
    {"certreq_critical",  KW_CERTREQ_CRITICAL},
    {"rightsourceip",     KW_RIGHTSOURCEIP},
    {"leftsourceif",      KW_LEFTSOURCEIF},
    {"lefthostaccess",    KW_LEFTHOSTACCESS},
    {"crluri1",           KW_CRLURI},
    {"device_identity",   KW_DEVICE_IDENTITY},
    {"mobike",	           KW_MOBIKE},
    {"rightallowany",     KW_RIGHTALLOWANY},
    {"forceencaps",       KW_FORCEENCAPS},
    {"leftupdown",        KW_LEFTUPDOWN},
    {"leftidr_apn",       KW_LEFTIDR_APN},
    {"rightprotoport",    KW_RIGHTPROTOPORT},
    {"rightforcetsi64",   KW_RIGHTFORCETSI64},
    {"leftpcscf",         KW_LEFTPCSCF},
    {"strictcrlpolicy",   KW_STRICTCRLPOLICY},
    {"rightnexthop",      KW_RIGHT_DEPRECATED},
    {"inactivity",        KW_INACTIVITY},
    {"hashandurl",        KW_HASHANDURL},
    {"ocspuri",           KW_OCSPURI},
    {"leftallowany",      KW_LEFTALLOWANY},
    {"mediation",         KW_MEDIATION},
    {"rightcustcpimei",   KW_RIGHTCUSTCPIMEI},
    {"leftimei",          KW_LEFTIMEI},
    {"type",              KW_TYPE},
    {"keepalivedelay",    KW_KEEPALIVEDELAY},
    {"righthostaccess",   KW_RIGHTHOSTACCESS},
    {"rightcustcppcscf6", KW_RIGHTCUSTCPPCSCF6},
    {"nat_traversal",     KW_SETUP_DEPRECATED},
    {"retrans_to",        KW_RETRANS_TO},
    {"also",              KW_ALSO},
    {"leftcustcpimei",    KW_LEFTCUSTCPIMEI},
    {"rightcert",         KW_RIGHTCERT},
    {"ike",               KW_IKE},
    {"leftcustcppcscf6",  KW_LEFTCUSTCPPCSCF6},
    {"esp",               KW_ESP},
    {"installpolicy",     KW_INSTALLPOLICY},
    {"crlcheckinterval",  KW_SETUP_DEPRECATED},
    {"ocspuri1",          KW_OCSPURI},
    {"klipsdebug",        KW_SETUP_DEPRECATED},
    {"ldapbase",          KW_CA_DEPRECATED},
    {"leftsubnet",        KW_LEFTSUBNET},
    {"leftimeiformat",    KW_LEFTIMEIFORMAT},
    {"rightca",           KW_RIGHTCA},
    {"mark_out",          KW_MARK_OUT},
    {"ikelifetime",       KW_IKELIFETIME},
    {"leftid",            KW_LEFTID},
    {"leftforcetsifull",  KW_LEFTFORCETSIFULL},
    {"mediated_by",       KW_MEDIATED_BY},
    {"rightauth",         KW_RIGHTAUTH},
    {"hidetos",           KW_SETUP_DEPRECATED},
    {"rightintnetmask",   KW_RIGHTINTNETMASK},
    {"pfsgroup",          KW_PFS_DEPRECATED},
    {"overridemtu",       KW_SETUP_DEPRECATED},
    {"leftsubnetwithin",  KW_LEFTSUBNET},
    {"rightupdown",       KW_RIGHTUPDOWN},
    {"fast_reauth",       KW_FAST_REAUTH},
    {"reauth_mbb",        KW_REAUTH_MBB},
    {"rekeyfuzz",         KW_REKEYFUZZ},
    {"leftikeport",       KW_LEFTIKEPORT},
    {"leftsourceip",      KW_LEFTSOURCEIP},
    {"leftikeportnatt",   KW_LEFTIKEPORTNATT},
    {"keyexchange",       KW_KEYEXCHANGE},
    {"ocsp",              KW_OCSP},
    {"cacert",            KW_CACERT},
    {"eap",               KW_CONN_DEPRECATED},
    {"leftintnetmask",    KW_LEFTINTNETMASK},
    {"leftcert2",         KW_LEFTCERT2},
    {"rightid2",          KW_RIGHTID2},
    {"rightcertpolicy",   KW_RIGHTCERTPOLICY},
    {"liveness_check",    KW_LIVENESS_CHECK},
    {"packetdefault",     KW_SETUP_DEPRECATED},
    {"mark",              KW_MARK},
    {"charondebug",       KW_CHARONDEBUG},
    {"leftforcetsi64",    KW_LEFTFORCETSI64},
    {"charonstart",       KW_SETUP_DEPRECATED},
    {"leftgroups2",       KW_LEFTGROUPS2},
    {"rekey",             KW_REKEY},
    {"rightgroups2",      KW_RIGHTGROUPS2},
    {"dpdaction",         KW_DPDACTION},
    {"encrkeydisplay",    KW_ENCRKEYDISPLAY},
    {"plutostderrlog",    KW_SETUP_DEPRECATED},
    {"plutostart",        KW_SETUP_DEPRECATED},
    {"aaa_identity",      KW_AAA_IDENTITY},
    {"closeaction",       KW_CLOSEACTION},
    {"tfc",               KW_TFC},
    {"leftca2",           KW_LEFTCA2},
    {"ah",                KW_AH},
    {"compress",          KW_COMPRESS},
    {"ldaphost",          KW_CA_DEPRECATED},
    {"is_emergency",      KW_IS_EMERGENCY},
    {"rightauth2",        KW_RIGHTAUTH2},
    {"auto",              KW_AUTO},
    {"rightcustcppcscf4", KW_RIGHTCUSTCPPCSCF4},
    {"oostimeout",        KW_OOSTIMEOUT},
    {"postpluto",         KW_SETUP_DEPRECATED},
    {"prepluto",          KW_SETUP_DEPRECATED},
    {"leftcustcppcscf4",  KW_LEFTCUSTCPPCSCF4},
    {"fragicmp",          KW_SETUP_DEPRECATED},
    {"me_peerid",         KW_ME_PEERID},
    {"leftauth",          KW_LEFTAUTH},
    {"crluri2",           KW_CRLURI2},
    {"wdrv_keepalive",    KW_WDRV_KEEPALIVE},
    {"eap_identity",      KW_EAP_IDENTITY},
    {"leftid2",           KW_LEFTID2},
    {"cachecrls",         KW_CACHECRLS},
    {"authby",            KW_AUTHBY},
    {"no_initct",         KW_NO_INIT_CONTACT},
    {"modeconfig",        KW_MODECONFIG},
    {"reauth",            KW_REAUTH},
    {"dumpdir",           KW_SETUP_DEPRECATED},
    {"force_keepalive",   KW_SETUP_DEPRECATED},
    {"xauth",             KW_XAUTH},
    {"dpddelay",          KW_DPDDELAY},
    {"pcscf_restore",     KW_PCSCF_RESTORE},
    {"nocrsend",          KW_SETUP_DEPRECATED},
    {"plutodebug",        KW_SETUP_DEPRECATED},
    {"skipcheckcert",     KW_SKIPCHECKCERT},
    {"pkcs11initargs",    KW_PKCS11_DEPRECATED},
    {"pkcs11module",      KW_PKCS11_DEPRECATED},
    {"pkcs11keepstate",   KW_PKCS11_DEPRECATED},
    {"rightca2",          KW_RIGHTCA2},
    {"rightcert2",        KW_RIGHTCERT2},
    {"ocspuri2",          KW_OCSPURI2},
    {"dpdtimeout",        KW_DPDTIMEOUT},
    {"dpd_noreply",       KW_DPD_NOREPLY},
    {"rekeymargin",       KW_REKEYMARGIN},
    {"leftauth2",         KW_LEFTAUTH2},
    {"ikedscp",           KW_IKEDSCP,},
    {"pkcs11proxy",       KW_PKCS11_DEPRECATED},
    {"skipcheckid",       KW_SKIPCHECKID},
    {"wsharkfiledump",    KW_WSHARKFILEDUMP},
    {"no_eaponly",        KW_NO_EAP_ONLY},
    {"xauth_identity",    KW_XAUTH_IDENTITY},
    {"addrchg_reauth",    KW_ADDRCHG_REAUTH}
  };

static const short lookup[] =
  {
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,   0,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   1,
     -1,  -1,  -1,  -1,  -1,  -1,   2,  -1,  -1,   3,
     -1,   4,  -1,  -1,  -1,  -1,   5,   6,  -1,   7,
     -1,   8,   9,  10,  11,  12,  13,  14,  15,  16,
     17,  18,  19,  -1,  20,  -1,  -1,  21,  22,  23,
     24,  -1,  25,  26,  -1,  -1,  27,  28,  -1,  29,
     -1,  30,  -1,  31,  -1,  32,  33,  34,  -1,  35,
     -1,  36,  -1,  37,  38,  39,  40,  41,  42,  43,
     44,  -1,  45,  46,  47,  48,  -1,  49,  50,  51,
     52,  53,  54,  55,  56,  57,  -1,  58,  59,  -1,
     60,  -1,  -1,  -1,  61,  -1,  -1,  62,  -1,  63,
     64,  65,  66,  -1,  67,  68,  -1,  69,  70,  71,
     72,  -1,  -1,  73,  -1,  74,  75,  76,  77,  78,
     79,  80,  81,  -1,  82,  83,  84,  85,  86,  -1,
     87,  -1,  -1,  88,  89,  90,  -1,  91,  92,  93,
     94,  95,  96,  97,  98,  99, 100, 101, 102, 103,
    104, 105, 106, 107, 108, 109, 110, 111, 112, 113,
    114, 115,  -1,  -1, 116,  -1, 117, 118, 119, 120,
    121, 122, 123, 124, 125, 126, 127, 128,  -1,  -1,
    129,  -1,  -1,  -1, 130, 131, 132, 133, 134,  -1,
    135,  -1, 136,  -1,  -1, 137, 138, 139, 140, 141,
    142, 143,  -1,  -1, 144,  -1, 145,  -1, 146,  -1,
    147,  -1, 148,  -1,  -1,  -1,  -1, 149,  -1, 150,
    151,  -1, 152,  -1,  -1, 153,  -1, 154,  -1,  -1,
     -1,  -1, 155,  -1, 156, 157,  -1, 158,  -1,  -1,
    159, 160,  -1, 161,  -1, 162,  -1,  -1, 163,  -1,
    164,  -1, 165, 166, 167,  -1,  -1, 168, 169,  -1,
     -1,  -1, 170, 171,  -1,  -1,  -1, 172,  -1, 173,
     -1, 174,  -1,  -1, 175,  -1,  -1,  -1, 176,  -1,
    177,  -1,  -1, 178, 179, 180, 181,  -1,  -1,  -1,
    182,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 183,  -1,
     -1, 184, 185,  -1,  -1, 186,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 187,  -1,
     -1, 188,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    189
  };

#ifdef __GNUC__
__inline
#if defined __GNUC_STDC_INLINE__ || defined __GNUC_GNU_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
const struct kw_entry *
in_word_set (str, len)
     register const char *str;
     register unsigned int len;
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = wordlist[index].name;

              if (*str == *s && !strcmp (str + 1, s + 1))
                return &wordlist[index];
            }
        }
    }
  return 0;
}
