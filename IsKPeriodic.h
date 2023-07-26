/* В итоговом домашнем задании вашей задачей будет написать функцию IsKPeriodic, которая проверяет, является ли строка кратной числу K.
Кратность — повторяемость строки каждые K символов (K должно быть больше 0). Например, abcabcabcabc имеет кратность 3, так как она состоит из подстрок abc, имеющих длину 3.
Задание следует загрузить в свой репозиторий на GitHub.
Ваш код будет оцениваться ментором курса, а значит, вы сможете получить вместе с баллом развёрнутый комментарий эксперта. Оцениваться задание будет максимум в 6 баллов по двум критериям: 
- эффективность алгоритма;
- оформление кода */
bool IsKPeriodic(const char* a, unsigned short b) {
	if (b <= 0) return 0; // Невалидное значение кратности
	long long c = 0; // Длина (в кол-ве символов) си-строки без завершающего ноль-символа
	while (a[c] != 0) ++c;
	if (c == 0) return 0; // Пустая строка
	if (b > c) return 0; // Строка короче подстроки
	if (c % b != 0) return 0; // Строка не кратна b
	int d = c / b; // Количество кратных подстрок
	for (int i = 1; i < d; ++i) {
		for (int j = 0; j < b; ++j) {
			if (a[j + b * i] != a[j]) return 0;
		}
	}
	return 1;
}
// cd c:\program_new\msys64\ucrt64\bin