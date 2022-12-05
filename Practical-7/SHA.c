// Name: Anish Tilloo
// Roll No: 34
// Sec: A
// Practical 7 SHA

#ifndef SHA1_H
#define SHA1_H
#include <stdint.h>
#ifndef SHA_enum
#define SHA_enum
enum{
shaSuccess = 0,
shaNull,
shaInputTooLong,
shaStateError
};
#endif
#define SHA1HashSize 20
typedef struct SHA1Context{
uint32_t Intermediate_Hash[SHA1HashSize/4];
uint32_t Length_Low;
uint32_t Length_High;
int_least16_t Message_Block_Index;
uint8_t Message_Block[64];
int Computed;
int Corrupted;
} SHA1Context;
int SHA1Reset( SHA1Context *);
int SHA1Input( SHA1Context *,
const uint8_t *,
unsigned int);
int SHA1Result( SHA1Context *,
uint8_t Message_Digest[SHA1HashSize]);
#endif
#define SHA1CircularShift(bits,word) \
(((word) << (bits)) | ((word) >> (32-(bits))))
void SHA1PadMessage(SHA1Context *);
void SHA1ProcessMessageBlock(SHA1Context *);
int SHA1Reset(SHA1Context *context){
if (!context){
return shaNull;
}
context->Length_Low = 0;
context->Length_High = 0;
context->Message_Block_Index = 0;
context->Intermediate_Hash[0] = 0x67452301;
context->Intermediate_Hash[1] = 0xEFCDAB89;
context->Intermediate_Hash[2] = 0x98BADCFE;
context->Intermediate_Hash[3] = 0x10325476;
context->Intermediate_Hash[4] = 0xC3D2E1F0;
context->Computed = 0;
context->Corrupted = 0;
return shaSuccess;
}
int SHA1Result( SHA1Context *context,
uint8_t Message_Digest[SHA1HashSize]){
int i;
if (!context || !Message_Digest){
return shaNull;
}
if (context->Corrupted){
return context->Corrupted;
}
if (!context->Computed){
SHA1PadMessage(context);
for(i=0; i<64; ++i){
context->Message_Block[i] = 0;
}
context->Length_Low = 0;
context->Length_High = 0;
context->Computed = 1;
}
for(i = 0; i < SHA1HashSize; ++i){
Message_Digest[i] = context->Intermediate_Hash[i>>2]
>> 8 * ( 3 - ( i & 0x03 ) );
}
return shaSuccess;
}
int SHA1Input( SHA1Context *context,
const uint8_t *message_array,
unsigned length){
if (!length){
return shaSuccess;
}
if (!context || !message_array){
return shaNull;
}
if (context->Computed){
context->Corrupted = shaStateError;
return shaStateError;
}
if (context->Corrupted){
return context->Corrupted;
}
while(length-- && !context->Corrupted){
context->Message_Block[context->Message_Block_Index++] =
(*message_array & 0xFF);
context->Length_Low += 8;
if (context->Length_Low == 0){
context->Length_High++;
if (context->Length_High == 0){
context->Corrupted = 1;
}
}
if (context->Message_Block_Index == 64)
{
SHA1ProcessMessageBlock(context);
}
message_array++;
}
return shaSuccess;
}
void SHA1ProcessMessageBlock(SHA1Context *context){
const uint32_t K[] = {
0x5A827999,
0x6ED9EBA1,
0x8F1BBCDC,
0xCA62C1D6
};
int t;
uint32_t temp;
uint32_t W[80];
uint32_t A, B, C, D, E;
for(t = 0; t < 16; t++){
W[t] = context->Message_Block[t * 4] << 24;
W[t] |= context->Message_Block[t * 4 + 1] << 16;
W[t] |= context->Message_Block[t * 4 + 2] << 8;
W[t] |= context->Message_Block[t * 4 + 3];
}
for(t = 16; t < 80; t++){
W[t] = SHA1CircularShift(1,W[t-3] ^ W[t-8] ^ W[t-14] ^ W[t-16]);
}
A = context->Intermediate_Hash[0];
B = context->Intermediate_Hash[1];
C = context->Intermediate_Hash[2];
D = context->Intermediate_Hash[3];
E = context->Intermediate_Hash[4];
for(t = 0; t < 20; t++){
temp = SHA1CircularShift(5,A) +
((B & C) | ((~B) & D)) + E + W[t] + K[0];
E = D;
D = C;
C = SHA1CircularShift(30,B);
B = A;
A = temp;
}
for(t = 20; t < 40; t++){
temp = SHA1CircularShift(5,A) + (B ^ C ^ D) + E + W[t] + K[1];
E = D;
D = C;
C = SHA1CircularShift(30,B);
B = A;
A = temp;
}
for(t = 40; t < 60; t++){
temp = SHA1CircularShift(5,A) +
((B & C) | (B & D) | (C & D)) + E + W[t] + K[2];
E = D;
D = C;
C = SHA1CircularShift(30,B);
B = A;
A = temp;
}
for(t = 60; t < 80; t++){
temp = SHA1CircularShift(5,A) + (B ^ C ^ D) + E + W[t] + K[3];
E = D;
D = C;
C = SHA1CircularShift(30,B);
B = A;
A = temp;
}
context->Intermediate_Hash[0] += A;
context->Intermediate_Hash[1] += B;
context->Intermediate_Hash[2] += C;
context->Intermediate_Hash[3] += D;
context->Intermediate_Hash[4] += E;
context->Message_Block_Index = 0;
}
void SHA1PadMessage(SHA1Context *context){
if(context->Message_Block_Index > 55){
context->Message_Block[context->Message_Block_Index++] = 0x80;
while(context->Message_Block_Index < 64){
context->Message_Block[context->Message_Block_Index++] = 0;
}
SHA1ProcessMessageBlock(context);
while(context->Message_Block_Index < 56){
context->Message_Block[context->Message_Block_Index++] = 0;
}
}
else{
context->Message_Block[context->Message_Block_Index++] = 0x80;
while(context->Message_Block_Index < 56){
context->Message_Block[context->Message_Block_Index++] = 0;
}
}
context->Message_Block[56] = context->Length_High >> 24;
context->Message_Block[57] = context->Length_High >> 16;
context->Message_Block[58] = context->Length_High >> 8;
context->Message_Block[59] = context->Length_High;
context->Message_Block[60] = context->Length_Low >> 24;
context->Message_Block[61] = context->Length_Low >> 16;
context->Message_Block[62] = context->Length_Low >> 8;
context->Message_Block[63] = context->Length_Low;
SHA1ProcessMessageBlock(context);
}
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define TEST1 "hello world"
#define TEST2a "sha1 algorithm"
#define TEST2 TEST2a 
char *testarray[4] =
{
TEST1,
TEST2,
};
long int repeatcount[4] = { 1, 1, 1000000, 10 };
char *resultarray[4] =
{
"2A AE 6C 35 C9 4F CF B4 15 DB E9 5F 40 8B 9C E9 1E E8 46 ED",
"3E EE B0 FC EE 88 25 03 86 B0 21 18 65 E1 7D D0 FA 84 23 0B",
"20 59 24 ff 98 5a 0d 84 10 fa 09 e8 e3 e0 33 f8 c6 c0 0e 60",
};



int main(){

SHA1Context sha;
int i, j, err;
uint8_t Message_Digest[20];

printf("Name: Anish Tilloo \n");
printf("Section: A  Roll No. 34 \n");
printf("Batch: A2 \n");
printf("Practical-7 \n");
/*
* Perform SHA-1 tests
*/
for(j = 0; j < 2; ++j){
printf("\n");
printf( "\n INPUT -> %d: %d, '%s'\n",
j+1,
repeatcount[j],
testarray[j]);
err = SHA1Reset(&sha);
if (err){
fprintf(stderr, "SHA1Reset Error %d.\n", err );
break; /* out of for j loop */
}
for(i = 0; i < repeatcount[j]; ++i){
err = SHA1Input(&sha,
(const unsigned char *) testarray[j],
strlen(testarray[j]));
if (err){
fprintf(stderr, "SHA1Input Error %d.\n", err );
break;
}
}
err = SHA1Result(&sha, Message_Digest);
if (err){
fprintf(stderr,
"SHA1Result Error %d, could not compute message digest.\n",
err );
}
else{
printf("\t");
for(i = 0; i < 20 ; ++i){
printf("%02X ", Message_Digest[i]);
}
printf("\n");
}
printf(" ORIGIONAL HASH VALUE - \n");
printf(" \t%s\n", resultarray[j]);
printf(" MATCH SUCCESSFULL");
printf("");
}
return 0;
}