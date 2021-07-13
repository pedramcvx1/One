/**
 The One Programming Language

 File: tokenizer/tokenizer.c
  _        _
 / \ |\ | |_    Max Base
 \_/ | \| |_    Copyright 2021; One Language Contributors

 **/

#include "tokenizer.h"

/*
 * @function: tokenizer_file
 * @description: Create a array of tokens from a filepath
 * @inputs: char* of a one' pathfile
 * @return: Array of Token
 */
Token** tokenizer_file(char* filepath)
{
	debug_tokenizer("tokenizer_file");
	debug_tokenizer("tokenizer_file: %s", filepath);

	char* data = file_reads(filepath);
	return tokenizer_string(data);
}

/*
 * @function: tokenizer_string
 * @description: Create a array of tokens from a one program source-code char*
 * @inputs: char* of a One program source-code
 * @return: Array of Token
 */
Token** tokenizer_string(char* data)
{
	debug_tokenizer("tokenizer_string");
	debug_tokenizer("tokenizer_string: %s", data);

	Array tokens;
	array_init(&tokens);

	while(*data != '\0') {
		Token* t = token_make();
		array_push(&tokens, t);
	}

	return (Token **)tokens.data;
}
