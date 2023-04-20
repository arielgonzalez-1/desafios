#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Ejecutar el script de la forma:
python3 csv2sql.py archivo.csv
"""

from datetime import datetime
import sys
import os
import csv

def clear_string(string):
    aux = list()
    for item in string.split(' '):
        if str(item) not in (' '):
            aux.append(item)
    aux = ' '.join(aux)
    return aux 

def csv2sql(path_csv, name, table):
    filename = name + ".sql"
    path_sql = f'./{filename}'
    str_list = [
        'equipoOP_ciudad',
        'equipoOP_codigo',
        'equipoOP_sigla',
        'equipoOP_conferencia',
        'equipoOP_division',
        'equipoOP_nombre',
        'stat_asistencias_nombre',
        'stat_bloqueos_nombre',
        'equipo_ciudad',
        'jugador_codigo',
        'pais',
        'stat_rebotes_defensivos_nombre',
        'equipo_sigla',
        'equipo_conferencia',
        'nombre_completo',
        'equipo_division',
        'fecha',
        'stat_tiros_intentos_nombre',
        'stat_tiros_convertidos_nombre',
        'nombre',
        'stat_faltas_nombre',
        'stat_tiros_libres_intentos_nombre',
        'stat_tiros_libres_convertidos_nombre',
        'esLocal',
        'apellido',
        'stat_minutos_nombre',
        'equipo_nombre',
        'stat_rebotes_ofensivos_nombre',
        'stat_puntos_nombre',
        'posicion',
        'stat_segundos_nombre',
        'stat_robos_nombre',
        'equipo_codigo',
        'stat_tiros_triples_intentos_nombre',
        'stat_tiros_triples_convertidos_nombre',
        'stat_perdidas_nombre',
        'peso',
        'resultado',
        'temporada_descripcion'
    ]
    if os.path.exists(path_sql):
        os.remove(path_sql)
    with open(path_csv) as csvfile:
        csvreader = csv.DictReader(csvfile)
        with open(path_sql, "a") as sqlfile:
            sqlfile.write("begin;\n")
            for row in csvreader:
                msg = ''
                keys = ''
                values = ''
                for key in row:
                    value = str(row[key])
                    aux = key.replace(' ', '').lower()
                    keys += f'{aux},'
                    if str(key) in str_list:
                        value = clear_string(value)
                        values += f'\'{value}\','
                    else:
                        values += f'{value},'
                    # print(key, '=>', value)
                msg = f'\n\ninsert into {table} ({keys[:-1]}) values ({values[:-1]});'
                sqlfile.write(msg)
            sqlfile.write("\ncommit;")

def main(argv):
    start = datetime.now()
    for filename in argv:
        path = f'./{filename}'
        name, extension = os.path.splitext(filename)
        if os.path.exists(path) and extension in ('.csv'):
            msg = f'Procesando archivo {name}'
            print(f'{"*" * len(msg)}\n{msg}\n{"*" * len(msg)}')
            csv2sql(path, name, 'datos')
        else:
            raise Exception('No encontrado o Extension incorrecta')
    stop = datetime.now()
    print(f'\nTiempo => {stop - start}')

if __name__ == '__main__':
    main(sys.argv[1:])