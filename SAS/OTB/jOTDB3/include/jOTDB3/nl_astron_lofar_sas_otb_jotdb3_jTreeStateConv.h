/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv */

#ifndef _Included_nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv
#define _Included_nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv
 * Method:    initTreeStateConv
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv_initTreeStateConv
  (JNIEnv *, jobject);

/*
 * Class:     nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv
 * Method:    get
 * Signature: (Ljava/lang/String;)S
 */
JNIEXPORT jshort JNICALL Java_nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv_get__Ljava_lang_String_2
  (JNIEnv *, jobject, jstring);

/*
 * Class:     nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv
 * Method:    get
 * Signature: (S)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv_get__S
  (JNIEnv *, jobject, jshort);

/*
 * Class:     nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv
 * Method:    getTypes
 * Signature: ()Ljava/util/HashMap;
 */
JNIEXPORT jobject JNICALL Java_nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv_getTypes
  (JNIEnv *, jobject);

/*
 * Class:     nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv
 * Method:    top
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv_top
  (JNIEnv *, jobject);

/*
 * Class:     nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv
 * Method:    next
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_nl_astron_lofar_sas_otb_jotdb3_jTreeStateConv_next
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
