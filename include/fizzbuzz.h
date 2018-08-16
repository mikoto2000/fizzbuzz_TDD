/** fizzbuzz 用の型定義 */
typedef unsigned char fizzbuzz_number_t;

/**
 * @fn fizzbuzz ルールに従い、番号に対応する回答を返却する。
 * @param (number) 回答が欲しい番号
 * @return         番号に対応する回答の文字列
 *
 * @description この関数で取得した文字列は、 fizzbuzz_free_answer() で開放してください。
 *
 */
char* fizzbuzz_get_answer(fizzbuzz_number_t number);

