/*
 * BNG Blaster (BBL) - OSPF Definitions
 *
 * Christian Giese, May 2023
 *
 * Copyright (C) 2020-2023, RtBrick, Inc.
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __BBL_OSPF_DEF_H__
#define __BBL_OSPF_DEF_H__

/* DEFINITIONS ... */

#define OSPF_DEFAULT_HELLO_INTERVAL         10
#define OSPF_DEFAULT_DEAD_INTERVAL          40
#define OSPF_DEFAULT_ROUTER_PRIORITY        64
#define OSPF_DEFAULT_METRIC                 10

#define OSPF_LSA_TYPES                      12

#define OSPF_LSA_LINK_P2P                   1
#define OSPF_LSA_LINK_TRANSIT               2
#define OSPF_LSA_LINK_STUB                  3
#define OSPF_LSA_LINK_VIRTUAL               4

#define OSPF_VERSION_2                      2
#define OSPF_VERSION_3                      3

#define OSPF_PDU_LEN_MIN                    16
#define OSPF_PDU_LEN_MAX                    UINT16_MAX

#define OSPFV2_HELLO_LEN_MIN                44
#define OSPFV3_HELLO_LEN_MIN                36
#define OSPFV2_DBD_LEN_MIN                  32
#define OSPFV3_DBD_LEN_MIN                  28

#define OSPF_TX_BUF_LEN                     1500
#define OSPF_MAX_SELF_LSA_LEN               1024

#define OSPF_OPTION_E_BIT                   0x02
#define OSPF_OPTION_LLS_BIT                 0x10

#define OSPF_DEFAULT_TEARDOWN_TIME          5

#define OSPF_LSA_GC_INTERVAL                30

#define OSPF_LSA_REFRESH_TIME               1800 /* 30 minutes */
#define OSPF_LSA_MAX_AGE                    3600 /* 1 hour */
#define OSPF_LSA_MAX_AGE_DIFF               900 /* 15 minutes */
#define OSPF_LSA_SEQ_INIT                   0x80000001
#define OSPF_LSA_SEQ_MAX                    0x7fffffff

#define OSPF_LSA_BORDER_ROUTER              0x01
#define OSPF_LSA_EXTERNAL_ROUTER            0x02

#define OSPF_OFFSET_VERSION                 0
#define OSPF_OFFSET_TYPE                    1
#define OSPF_OFFSET_PACKET_LEN              2
#define OSPF_OFFSET_ROUTER_ID               4
#define OSPF_OFFSET_AREA_ID                 8
#define OSPF_OFFSET_CHECKSUM                12

#define OSPFV2_OFFSET_AUTH_TYPE             14
#define OSPFV2_OFFSET_AUTH_DATA             16
#define OSPFV2_OFFSET_PACKET                24

#define OSPFV3_OFFSET_INSTANCE_ID           14
#define OSPFV3_OFFSET_PACKET                16

#define OSPFV2_OFFSET_HELLO_NETMASK         24
#define OSPFV2_OFFSET_HELLO_INTERVAL        28
#define OSPFV2_OFFSET_HELLO_OPTIONS         30
#define OSPFV2_OFFSET_HELLO_PRIORITY        31
#define OSPFV2_OFFSET_HELLO_DEAD_INTERVAL   32
#define OSPFV2_OFFSET_HELLO_DR              36
#define OSPFV2_OFFSET_HELLO_BDR             40
#define OSPFV2_OFFSET_HELLO_NBR             44

#define OSPFV3_OFFSET_HELLO_INTERFACE_ID    16
#define OSPFV3_OFFSET_HELLO_PRIORITY        20
#define OSPFV3_OFFSET_HELLO_OPTIONS         21
#define OSPFV3_OFFSET_HELLO_INTERVAL        24
#define OSPFV3_OFFSET_HELLO_DEAD_INTERVAL   26
#define OSPFV3_OFFSET_HELLO_DR              28
#define OSPFV3_OFFSET_HELLO_BDR             32
#define OSPFV3_OFFSET_HELLO_NBR             36

#define OSPFV2_OFFSET_DBD_MTU               24
#define OSPFV2_OFFSET_DBD_OPTIONS           26
#define OSPFV2_OFFSET_DBD_FLAGS             27
#define OSPFV2_OFFSET_DBD_DD_SEQ            28
#define OSPFV2_OFFSET_DBD_LSA               32

#define OSPFV3_OFFSET_DBD_OPTIONS           17
#define OSPFV3_OFFSET_DBD_MTU               20
#define OSPFV3_OFFSET_DBD_FLAGS             23
#define OSPFV3_OFFSET_DBD_DD_SEQ            24
#define OSPFV3_OFFSET_DBD_LSA               28

#define OSPF_DBD_FLAG_MS                    0x01
#define OSPF_DBD_FLAG_M                     0x02
#define OSPF_DBD_FLAG_I                     0x04
#define OSPF_DBD_FLAG_R                     0x08

#define OSPF_DBD_OPTION_MT                  0x01
#define OSPF_DBD_OPTION_E                   0x02
#define OSPF_DBD_OPTION_MC                  0x04
#define OSPF_DBD_OPTION_N                   0x08
#define OSPF_DBD_OPTION_L                   0x10
#define OSPF_DBD_OPTION_DC                  0x20
#define OSPF_DBD_OPTION_O                   0x40
#define OSPF_DBD_OPTION_DN                  0x80

#define OSPF_EXTENDED_OPTION_TLV            1
#define OSPF_EXTENDED_OPTION_TLV_LEN        4

#define OSPF_EXT_OPTION_LSDB_RESYNC         0x01
#define OSPF_EXT_OPTION_RESTART             0x02

#define OSPFV2_AUTH_DATA_LEN                8

#define OSPF_LSA_HDR_LEN                    20
#define OSPF_LLS_HDR_LEN                    12


typedef struct ospf_config_ ospf_config_s;
typedef struct ospf_instance_ ospf_instance_s;
typedef struct ospf_interface_ ospf_interface_s;
typedef struct ospf_neighbor_ ospf_neighbor_s;

/* ENUMS ... */

typedef enum ospf_interface_type_ {
    OSPF_INTERFACE_P2P          = 0,
    OSPF_INTERFACE_BROADCAST    = 1,
    OSPF_INTERFACE_VIRTUAL      = 2,
    OSPF_INTERFACE_NBMA         = 3,
    OSPF_INTERFACE_P2M          = 4
} ospf_interface_type;    

typedef enum ospf_interface_state_ {
    OSPF_IFSTATE_DOWN       = 0,
    OSPF_IFSTATE_LOOPBACK   = 1,
    OSPF_IFSTATE_WAITING    = 2,
    OSPF_IFSTATE_P2P        = 3,
    OSPF_IFSTATE_DR_OTHER   = 4,
    OSPF_IFSTATE_BACKUP     = 5,
    OSPF_IFSTATE_DR         = 6
} ospf_interface_state;

typedef enum ospf_neighbor_state_ {
    OSPF_NBSTATE_DOWN       = 0,
    OSPF_NBSTATE_ATTEMPT    = 1,
    OSPF_NBSTATE_INIT       = 2,
    OSPF_NBSTATE_2WAY       = 3,
    OSPF_NBSTATE_EXSTART    = 4,
    OSPF_NBSTATE_EXCHANGE   = 5,
    OSPF_NBSTATE_LOADING    = 6,
    OSPF_NBSTATE_FULL       = 7
} ospf_neighbor_state;

typedef enum ospf_adjacency_state_ {
    OSPF_ADJACENCY_STATE_DOWN   = 0,
    OSPF_ADJACENCY_STATE_UP     = 1
} ospf_adjacency_state;    

typedef enum ospf_p2p_adjacency_state_ {
    OSPF_P2P_ADJACENCY_STATE_UP     = 0,
    OSPF_P2P_ADJACENCY_STATE_INIT   = 1,
    OSPF_P2P_ADJACENCY_STATE_DOWN   = 2
} ospf_p2p_adjacency_state;

typedef enum ospf_auth_type_ {
    OSPF_AUTH_NONE              = 0,
    OSPF_AUTH_CLEARTEXT         = 1,
    OSPF_AUTH_MD5               = 2
} __attribute__ ((__packed__)) ospf_auth_type;

typedef enum ospf_lsa_source_ {
    OSPF_SOURCE_SELF,       /* Self originated LSA */
    OSPF_SOURCE_ADJACENCY,  /* LSA learned from neighbors */
    OSPF_SOURCE_EXTERNAL    /* LSA injected externally (e.g. MRT file, ...) */
} ospf_lsa_source;

typedef enum ospf_pdu_type_ {
    OSPF_PDU_HELLO      = 1,
    OSPF_PDU_DB_DESC    = 2,
    OSPF_PDU_LS_REQUEST = 3,
    OSPF_PDU_LS_UPDATE  = 4,
    OSPF_PDU_LS_ACK     = 5,
} ospf_pdu_type;

typedef enum ospf_lsa_type_ {
    OSPF_LSA_TYPE_1     = 1,
    OSPF_LSA_TYPE_2     = 2,
    OSPF_LSA_TYPE_3     = 3,
    OSPF_LSA_TYPE_4     = 4,
    OSPF_LSA_TYPE_5     = 5,
    OSPF_LSA_TYPE_6     = 6,
    OSPF_LSA_TYPE_7     = 7,
    OSPF_LSA_TYPE_8     = 8,
    OSPF_LSA_TYPE_9     = 9,
    OSPF_LSA_TYPE_10    = 10,
    OSPF_LSA_TYPE_11    = 11,
    OSPF_LSA_TYPE_MAX,
} ospf_lsa_type;

typedef enum ospf_lsa_scope_ {
    OSPF_LSA_SCOPE_LINK_LOCAL   = 0x0,
    OSPF_LSA_SCOPE_AREA         = 0x2,
    OSPF_LSA_SCOPE_AS           = 0x4
} ospf_lsa_scope;

/* STRUCTURES ... */

typedef struct ospf_lsa_key_ {
    uint8_t     type; /* LS Type */
    uint32_t    id; /* Link State ID */
    uint32_t    router; /* Advertising Router */
} __attribute__ ((__packed__)) ospf_lsa_key_s;

typedef struct ospf_external_connection_ {
    const char         *router_id_str;
    ipv4addr_t          router_id;
    uint32_t            metric;
    struct ospf_external_connection_ *next;
} ospf_external_connection_s;

/*
 * OSPF Instance Configuration
 */
typedef struct ospf_config_ {

    uint16_t id; /* OSPF instance identifier */
    uint8_t  version; /* OSPF version (default 2) */

    const char         *area_str;
    ipv4addr_t          area;

    const char         *router_id_str;
    ipv4addr_t          router_id;
    uint8_t             router_priority;

    bool                overload;

    ospf_auth_type      auth_type;
    char               *auth_key;

    uint16_t            hello_interval;
    uint16_t            dead_interval;

    uint16_t            teardown_time;

    const char         *hostname;

    char *external_mrt_file;
    struct ospf_external_connection_ *external_connection;

    /* Pointer to next instance */
    struct ospf_config_ *next; 
} ospf_config_s;

typedef struct ospf_neighbor_ {
    ospf_interface_s *interface;
    ospf_neighbor_s *next;

    uint32_t router_id;

    uint8_t  version; /* OSPF version */
    uint8_t  priority;
    uint8_t  options;

    bool     master;
    bool     oob_resync;

    uint32_t dr;
    uint32_t bdr;
    uint32_t dd;
    uint8_t state;

    ospf_lsa_key_s dbd_lsa_start; /* DBD LSA cursor */
    ospf_lsa_key_s dbd_lsa_next; /* DBD LSA cursor */

    bool dbd_more; /* DBD LSA cursor */

    hb_tree *flood_tree; /* Send LS Update */
    hb_tree *request_tree; /* Send LS Request */
    hb_tree *ack_tree;

    struct timer_   *timer_tx;
    struct timer_   *timer_retry;
    struct timer_   *timer_request;
    struct timer_   *timer_ack;
    struct timer_   *timer_inactivity;

} ospf_neighbor_s;

typedef struct ospf_interface_ {
    bbl_network_interface_s *interface;
    ospf_instance_s *instance;
    ospf_neighbor_s *neighbors;
    ospf_interface_s *next;
    
    uint8_t version;    /* OSPF version */
    uint8_t type;       /* OSPF inteface type (P2P, broadcast, ...) */
    uint8_t state;

    uint16_t max_len; /* max OSPF payload len without fragmentation */
    uint16_t max_fragment_len; /* max OSPF payload len with fragmentation */

    uint16_t metric;

    uint32_t dr;
    uint32_t bdr;
    struct {
        uint32_t hello_rx;
        uint32_t hello_tx;
        uint32_t db_des_rx;
        uint32_t db_des_tx;
        uint32_t ls_req_rx;
        uint32_t ls_req_tx;
        uint32_t ls_upd_rx;
        uint32_t ls_upd_tx;
        uint32_t ls_ack_rx;
        uint32_t ls_ack_tx;
    } stats;

    struct timer_  *timer_hello;

} ospf_interface_s;

typedef struct ospf_instance_ {
    ospf_config_s  *config;
    bool            overload;

    bool            teardown;
    struct timer_  *timer_teardown;
    struct timer_  *timer_lsa_gc;

    hb_tree *lsdb;

    ospf_interface_s *interfaces;

    struct ospf_instance_ *next; /* pointer to next instance */
} ospf_instance_s;

/*
 * OSPF PDU context
 */
typedef struct ospf_pdu_ {
    uint8_t  pdu_type;
    uint8_t  pdu_version;

    uint32_t router_id;
    uint32_t area_id;
    uint16_t checksum;

    uint8_t  auth_type;
    uint8_t  auth_data_len;
    uint16_t auth_data_offset;
    uint16_t packet_len;

    void    *source; /* souce IPv4/v6 address*/
    void    *destination; /* destination IPv4/v6 address*/

    uint16_t cur; /* current position */
    uint8_t *pdu; /* whole PDU inlcuding trailer */
    uint16_t pdu_len;
    uint16_t pdu_buf_len;
} ospf_pdu_s;

typedef struct ospf_lsa_header_ {
    uint16_t    age; /* LS Age */
    uint8_t     options; /* Options */
    uint8_t     type; /* LS Type */
    uint32_t    id; /* Link State ID */
    uint32_t    router; /* Advertising Router */
    uint32_t    seq; /* Sequence Number */
    uint16_t    checksum; /* Checksum */
    uint16_t    length; /* Length */
} __attribute__ ((__packed__)) ospf_lsa_header_s;

typedef struct ospf_lsa_link_s {
    uint32_t    link_id; /* Link ID */
    uint32_t    link_data; /* Link Data */
    uint8_t     type; /* Type */
    uint8_t     tos; /* Tos */
    uint16_t    metric; /* Metric */
} __attribute__ ((__packed__)) ospf_lsa_link_s;

typedef struct ospf_lsa_ {
    ospf_instance_s *instance;

    ospf_lsa_key_s key;
    struct {
        ospf_lsa_source type;
        uint32_t router_id;
    } source;

    /* LSA receive timestamp and age */
    struct timespec timestamp;
    uint16_t age;

    struct timer_ *timer_lifetime;
    struct timer_ *timer_refresh;

    uint32_t seq; /* Sequence Number */
    uint32_t refcount;
    bool expired;
    bool deleted;

    char *auth_key;

    uint8_t *lsa;
    uint16_t lsa_len;
    uint16_t lsa_buf_len;
} ospf_lsa_s;

typedef struct ospf_flood_entry_ {
    ospf_lsa_s     *lsa;
    bool            wait_ack;
    uint32_t        tx_count;
    struct timespec tx_timestamp;
} ospf_flood_entry_s;

typedef struct ospf_request_entry_ {
    ospf_lsa_key_s key;
} ospf_request_entry_s;

#endif