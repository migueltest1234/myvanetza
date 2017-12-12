/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "CDD_TS102894-2/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example`
 */

#ifndef	_PathDeltaTime_H_
#define	_PathDeltaTime_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PathDeltaTime {
	PathDeltaTime_tenMilliSecondsInPast	= 1
} e_PathDeltaTime;

/* PathDeltaTime */
typedef long	 PathDeltaTime_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_PathDeltaTime_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_PathDeltaTime;
asn_struct_free_f PathDeltaTime_free;
asn_struct_print_f PathDeltaTime_print;
asn_constr_check_f PathDeltaTime_constraint;
ber_type_decoder_f PathDeltaTime_decode_ber;
der_type_encoder_f PathDeltaTime_encode_der;
xer_type_decoder_f PathDeltaTime_decode_xer;
xer_type_encoder_f PathDeltaTime_encode_xer;
oer_type_decoder_f PathDeltaTime_decode_oer;
oer_type_encoder_f PathDeltaTime_encode_oer;
per_type_decoder_f PathDeltaTime_decode_uper;
per_type_encoder_f PathDeltaTime_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _PathDeltaTime_H_ */
#include "asn_internal.h"