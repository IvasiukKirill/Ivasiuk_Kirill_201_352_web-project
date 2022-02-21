# -*- coding: utf-8 -*-
"""
Задание 6.2

Запросить у пользователя ввод IP-адреса в формате 10.0.1.1
В зависимости от типа адреса (описаны ниже), вывести на стандартный поток вывода:
   'unicast' - если первый байт в диапазоне 1-223
   'multicast' - если первый байт в диапазоне 224-239
   'local broadcast' - если IP-адрес равен 255.255.255.255
   'unassigned' - если IP-адрес равен 0.0.0.0
   'unused' - во всех остальных случаях

Ограничение: Все задания надо выполнять используя только пройденные темы.
"""
from itertools import count


local_broadcast=('255.255.255.255')
unassigned=('0.0.0.0')
ip=input('Введите ip-address: ')
oktets=ip.split('.')
if int(oktets[0]) in range(1,224):
   print('unicast')
elif int(oktets[0]) in range(224,240):
      print('multicast')
elif ip == local_broadcast:
      print('local broadcast')
elif ip == unassigned:
   print('unassigned')   
else:
   print('unused')
   