# -*- coding: utf-8 -*-
"""
Задание 7.2b

Переделать скрипт из задания 7.2a: вместо вывода на стандартный поток вывода,
скрипт должен записать полученные строки в файл

Имена файлов нужно передавать как аргументы скрипту:
 * имя исходного файла конфигурации
 * имя итогового файла конфигурации

При этом, должны быть отфильтрованы строки, которые содержатся в списке ignore
и строки, которые начинаются на '!'.

Ограничение: Все задания надо выполнять используя только пройденные темы.

"""

ignore = ["duplex", "alias", "configuration"]

from sys import argv
text = argv[1:]
text = ''.join(text)
ignore = ['duplex', 'alias', 'Current configuration']
with open(text, 'r') as file, open('config_sw1_cleared.txt', 'a') as f:
    for line in file:
        if line.find(ignore[0]) is -1 and line.find(ignore[1]) is -1 and line.find(ignore[2]) is -1 and line.find('!') is -1:
            f.write(line)
