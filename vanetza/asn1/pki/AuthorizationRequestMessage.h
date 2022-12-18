/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EtsiTs102941MessagesCa"
 * 	found in "asn1/TS102941v131-MessagesCa.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_AuthorizationRequestMessage_H_
#define	_AuthorizationRequestMessage_H_


#include "asn_application.h"

/* Including external dependencies */
#include "EtsiTs103097Data-Encrypted-Unicast.h"

#ifdef __cplusplus
extern "C" {
#endif

/* AuthorizationRequestMessage */
typedef EtsiTs103097Data_Encrypted_Unicast_55P0_t	 AuthorizationRequestMessage_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AuthorizationRequestMessage;
asn_struct_free_f AuthorizationRequestMessage_free;
asn_struct_print_f AuthorizationRequestMessage_print;
asn_constr_check_f AuthorizationRequestMessage_constraint;
ber_type_decoder_f AuthorizationRequestMessage_decode_ber;
der_type_encoder_f AuthorizationRequestMessage_encode_der;
xer_type_decoder_f AuthorizationRequestMessage_decode_xer;
xer_type_encoder_f AuthorizationRequestMessage_encode_xer;
jer_type_encoder_f AuthorizationRequestMessage_encode_jer;
oer_type_decoder_f AuthorizationRequestMessage_decode_oer;
oer_type_encoder_f AuthorizationRequestMessage_encode_oer;
per_type_decoder_f AuthorizationRequestMessage_decode_uper;
per_type_encoder_f AuthorizationRequestMessage_encode_uper;
per_type_decoder_f AuthorizationRequestMessage_decode_aper;
per_type_encoder_f AuthorizationRequestMessage_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _AuthorizationRequestMessage_H_ */
#include "asn_internal.h"
