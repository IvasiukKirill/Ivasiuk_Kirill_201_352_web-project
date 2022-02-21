# -*- coding: utf-8 -*-
"""
Задание 6.2b

Сделать копию скрипта задания 6.2a.

Дополнить скрипт: Если адрес был введен неправильно, запросить адрес снова.

Если адрес задан неправильно, выводить сообщение: 'Неправильный IP-адрес'
Сообщение "Неправильный IP-адрес" должно выводиться только один раз,
даже если несколько пунктов выше не выполнены.

Ограничение: Все задания надо выполнять используя только пройденные темы.
"""
from gettext import find
from tracemalloc import stop


x=0
local_broadcast=('255.255.255.255')
unassigned=('0.0.0.0')

while x==0:
    ip=input('Введите ip-address: ')
    oktets=ip.split('.')
    for x in range (4):
        if oktets[x].isdigit() and int(oktets[x])in range(0,256) and ip.find('.')==3  :
            x+=1
        else:
         print('Неправильный IP-адрес')
         x=0
         
       
   

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
   