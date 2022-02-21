# -*- coding: utf-8 -*-
"""
Задание 7.3b

Сделать копию скрипта задания 7.3a.

Переделать скрипт:
- Запросить у пользователя ввод номера VLAN.
- Выводить информацию только по указанному VLAN.

Пример работы скрипта:

Enter VLAN number: 10
10       0a1b.1c80.7000      Gi0/4
10       01ab.c5d0.70d0      Gi0/8

Ограничение: Все задания надо выполнять используя только пройденные темы.

"""
vlan = input('Введите VLAN ID: ')
with open('07_files\CAM_table.txt', 'r') as start:
    lists = [] 
    for line in start: 
        if line.count('.') == 2: 
            a = line.strip('\n').split() 
            a.pop(-2) 
            if a[0] == vlan:
                print(a[0] + '    ' + a[1] + '   ' + a[2])