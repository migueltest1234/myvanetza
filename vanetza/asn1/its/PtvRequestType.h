/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "AddGrpC"
 * 	found in "build.asn1/iso/ISO19091.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_PtvRequestType_H_
#define	_PtvRequestType_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PtvRequestType {
	PtvRequestType_preRequest	= 0,
	PtvRequestType_mainRequest	= 1,
	PtvRequestType_doorCloseRequest	= 2,
	PtvRequestType_cancelRequest	= 3,
	PtvRequestType_emergencyRequest	= 4
	/*
	 * Enumeration is extensible
	 */
} e_PtvRequestType;

/* PtvRequestType */
typedef long	 PtvRequestType_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_PtvRequestType_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_PtvRequestType;
extern const asn_INTEGER_specifics_t asn_SPC_PtvRequestType_specs_1;
asn_struct_free_f PtvRequestType_free;
asn_struct_print_f PtvRequestType_print;
asn_constr_check_f PtvRequestType_constraint;
ber_type_decoder_f PtvRequestType_decode_ber;
der_type_encoder_f PtvRequestType_encode_der;
xer_type_decoder_f PtvRequestType_decode_xer;
xer_type_encoder_f PtvRequestType_encode_xer;
jer_type_encoder_f PtvRequestType_encode_jer;
oer_type_decoder_f PtvRequestType_decode_oer;
oer_type_encoder_f PtvRequestType_encode_oer;
per_type_decoder_f PtvRequestType_decode_uper;
per_type_encoder_f PtvRequestType_encode_uper;
per_type_decoder_f PtvRequestType_decode_aper;
per_type_encoder_f PtvRequestType_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _PtvRequestType_H_ */
#include "asn_internal.h"
