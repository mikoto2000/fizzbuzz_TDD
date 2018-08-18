/** fizzbuzz 用の型定義 */
typedef unsigned char fizzbuzz_number_t;
typedef char* fizzbuzz_answer_t;

/**
 * @fn fizzbuzz ルールに従い、番号に対応する回答を返却する。
 * @param (number) 回答が欲しい番号
 * @return         番号に対応する回答の文字列
 *
 * @description この関数で取得した文字列は、 fizzbuzz_free_answer() で開放してください。
 *
 * @see fizzbuzz_free_answer
 *
 */
fizzbuzz_answer_t fizzbuzz_get_answer(fizzbuzz_number_t number);

/**
 * @fn fizzbuzz_get_answer で取得したメモリを解放する。
 * @param (answer) 解放したい回答
 *
 * @see fizzbuzz_get_answer
 *
 */
void fizzbuzz_free_answer(fizzbuzz_answer_t answer);

/**
 * @fn fizzbuzz ルールに従い、1 から指定された番号までの回答を返却する。
 * @param (number) 1 からこの番号までの回答を返却する
 * @return         1 から番号までの回答を格納した配列
 *
 * @description この関数で取得した文字列は、 fizzbuzz_free_answer_array() で開放してください。
 *
 * example:
 *     >>> fizzbuzz_get_answer_array(3)
 *     ["1", "2", "Fizz"]
 */
char** fizzbuzz_get_answer_array(fizzbuzz_number_t number);
