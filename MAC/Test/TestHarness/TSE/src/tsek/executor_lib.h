/*=========================================================================
// (c)   Ordina Technical Automation BV
//
// The Intellectual Property Rights of this source code file is not transferable.
// For information on this subject, contact Ordina Technical Automation B.V.
// Any attempt or participation in deciphering, decoding, reverse engineering or
// in any way altering the source code is strictly prohibited, unless the prior
// written consent of Ordina Technical Automation B.V. is obtained.
//
// Project       : Script Engine
// Module/Systeem: Script Engine
//
// --- Version Control ---
//    $RCSfile$
//    $Revision: 5446 $
//    $Date: 2005-06-15 12:59:23 +0000 (Wed, 15 Jun 2005) $
// -----------------------
//
// Description   : 
//
// Revisions:
//
// Date       Author                  Changes
// 08/10/2000 E.A. Nijboer            Initial release
// 12/01/2001 E.A. Nijboer            platform test.
// 09/02/2001 E.A. Nijboer            
//
//=========================================================================
*/


#include "codingstandard.h"
#include "general_lib.h"

int16     iRandom(
  int16 iMax);
void      ar_or(
  char *pcA,
  char *pcB);
void      ar_and(
  char *pcA,
  char *pcB);

void      TryTransferState(
  struct TStateMachine *ptStateMachine,
  struct TTransition *ptTransition);

void      TransferState(
  struct TStateMachine *ptStateMachine,
  struct TTransition *ptTransition);

void      InitBoards(
  struct TBoardList *ptBoardList);
char     *DeviceName(
  int16 i);


/* Signalling constants. Used for values of type _tSignal. Pointers refer-   */
/* ring to this values may never be freed.                                   */

extern char *_NO_SIGNAL;
extern char *_SIGNAL;
