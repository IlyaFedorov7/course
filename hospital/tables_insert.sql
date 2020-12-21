insert into Smena(Kod_Sm, Coeff_2, Data_S) values (102, 0.5, '2020-10-11')
insert into Smena(Kod_Sm, Coeff_2, Data_S) values (103, 1.75, '2020-10-12')
insert into Smena(Kod_Sm, Coeff_2, Data_S) values (104, 1.25, '2020-10-13')
insert into Smena(Kod_Sm, Coeff_2, Data_S) values (105, 1.5, '2020-10-14')
insert into Specializacia(Kod_Sp, Name_type, Oklad) values (1001, 'Стоматолог-терапевт', 30000)
insert into Specializacia(Kod_Sp, Name_type, Oklad) values (1002, 'Стоматолог-ортопед', 35000)
insert into Specializacia(Kod_Sp, Name_type, Oklad) values (1003, 'Стоматолог-хирург', 40000)
insert into Specializacia(Kod_Sp, Name_type, Oklad) values (1004, 'Стоматолог детский', 32500)
insert into Specializacia(Kod_Sp, Name_type, Oklad) values (1005, 'Зубной техник', 37500)
insert into Vziskania(Kod_Vz, Name_type, Summa) values (1000001, 'Опоздание на рабочее место', 2000)
insert into Vziskania(Kod_Vz, Name_type, Summa) values (1000002, 'Нахождение на рабочем месте в состоянии алкогольного опьянения', 15000)
insert into Vziskania(Kod_Vz, Name_type, Summa) values (1000003, 'Отсутствие на рабочем месте без уважительной причины', 5000)
insert into Vziskania(Kod_Vz, Name_type, Summa) values (1000004, 'Нарушение правил пожарной безопасности на рабочем месте', 4000)
insert into Vziskania(Kod_Vz, Name_type, Summa) values (1000005, 'Нарушение ведения документации',3000)
insert into Vyzovy(Kod_V, DataVremya, Nadbavka) values (20200001, '2020-10-10 10:00:00', 1000)
insert into Vyzovy(Kod_V, DataVremya, Nadbavka) values (20200002, '2020-10-10 15:00:00', 500)
insert into Vyzovy(Kod_V, DataVremya, Nadbavka) values (20200003, '2020-10-11 09:00:00', 700)
insert into Vyzovy(Kod_V, DataVremya, Nadbavka) values (20200004, '2020-10-12 16:00:00', 400)
insert into Vyzovy(Kod_V, DataVremya, Nadbavka) values (20200005, '2020-10-13 13:00:00', 600)
insert into Stazh(Kod_S, Obrazovanie, Opyt, Coeff_1) values (100001, 'высшее, ординатура, Нижний Новгород', 'работа в стоматологии 4 года', 1.5) 
insert into Stazh(Kod_S, Obrazovanie, Opyt, Coeff_1) values (100002, 'высшее, специалист, Москва', 'работа в стоматологии 6 лет', 1.8)
insert into Stazh(Kod_S, Obrazovanie, Opyt, Coeff_1) values (100003, 'высшее, магистратура, Санкт-Петербург', 'работа в больнице 2 года', 1.3)
insert into Stazh(Kod_S, Obrazovanie, Opyt, Coeff_1) values (100004, 'высшее, диссертантура, Пенза', 'работа в стоматологии 8 лет', 2.0)
insert into Stazh(Kod_S, Obrazovanie, Opyt, Coeff_1) values (100005, 'высшее, аспирантура, Казань', 'работа в больнице 5 лет', 1.6)
insert into Tabel(Num, Kolvo_chasov) values (20201010001, 8)
insert into Tabel(Num, Kolvo_chasov) values (20201010002, 9)
insert into Tabel(Num, Kolvo_chasov) values (20201010003, 7)
insert into Tabel(Num, Kolvo_chasov) values (20201010004, 4)
insert into Tabel(Num, Kolvo_chasov) values (20201010005, 2)
insert into ZpVedomost(Kod_Z, Vyplata_oklad, Vyplata_gen) values (999999991, 100, 0)
insert into ZpVedomost(Kod_Z, Vyplata_oklad, Vyplata_gen) values (999999992, 100, 0)
insert into ZpVedomost(Kod_Z, Vyplata_oklad, Vyplata_gen) values (999999993, 100, 0)
insert into ZpVedomost(Kod_Z, Vyplata_oklad, Vyplata_gen) values (999999994, 100, 0)
insert into ZpVedomost(Kod_Z,  Vyplata_oklad, Vyplata_gen) values (999999995, 100, 0)
insert into Vrach(ID, Kod_Z_ZpVedomost, Kod_S_Stazh, FIO, Kfalifikacia) values (1, 999999991, 100001, 'Иванов Иван Иванович', 'Врач-терапевт')
insert into Vrach(ID, Kod_Z_ZpVedomost, Kod_S_Stazh, FIO, Kfalifikacia) values (2, 999999992, 100002, 'Петров Петр Петрович', 'Врач-стоматолог')
insert into Vrach(ID, Kod_Z_ZpVedomost, Kod_S_Stazh, FIO, Kfalifikacia) values (3, 999999993, 100003, 'Федоров Федор Федорович', 'Врач-хирург')
insert into Vrach(ID, Kod_Z_ZpVedomost, Kod_S_Stazh, FIO, Kfalifikacia) values (4, 999999994, 100004, 'Сергеев Сергей Сергеевич', 'Врач-педиатр')
insert into Vrach(ID, Kod_Z_ZpVedomost, Kod_S_Stazh, FIO, Kfalifikacia) values (5, 999999995, 100005, 'Данилов Данила Данилович', 'Врач-стоматолог')
insert into Smena_and_Vrach(Kod_Sm_Smena, ID_Vrach) values (101, 1)
insert into Smena_and_Vrach(Kod_Sm_Smena, ID_Vrach) values (102, 2)
insert into Smena_and_Vrach(Kod_Sm_Smena, ID_Vrach) values (103, 3)
insert into Smena_and_Vrach(Kod_Sm_Smena, ID_Vrach) values (104, 4)
insert into Smena_and_Vrach(Kod_Sm_Smena, ID_Vrach) values (105, 5)
insert into Specializacia_and_Vrach(Kod_Sp_Specializacia, ID_Vrach) values (1001, 1)
insert into Specializacia_and_Vrach(Kod_Sp_Specializacia, ID_Vrach) values (1002, 2)
insert into Specializacia_and_Vrach(Kod_Sp_Specializacia, ID_Vrach) values (1003, 3)
insert into Specializacia_and_Vrach(Kod_Sp_Specializacia, ID_Vrach) values (1004, 4)
insert into Specializacia_and_Vrach(Kod_Sp_Specializacia, ID_Vrach) values (1005, 5)
insert into Vziskania_and_Vrach(Kod_Vz_Vziskania, ID_Vrach) values (1000001, 1)
insert into Vziskania_and_Vrach(Kod_Vz_Vziskania, ID_Vrach) values (1000002, 2)
insert into Vziskania_and_Vrach(Kod_Vz_Vziskania, ID_Vrach) values (1000003, 3)
insert into Vziskania_and_Vrach(Kod_Vz_Vziskania, ID_Vrach) values (1000004, 4)
insert into Vziskania_and_Vrach(Kod_Vz_Vziskania, ID_Vrach) values (1000005, 5)
insert into Vyzovy_and_Vrach(Kod_V_Vyzovy, ID_Vrach) values (20200001, 1)
insert into Vyzovy_and_Vrach(Kod_V_Vyzovy, ID_Vrach) values (20200002, 2)
insert into Vyzovy_and_Vrach(Kod_V_Vyzovy, ID_Vrach) values (20200003, 3)
insert into Vyzovy_and_Vrach(Kod_V_Vyzovy, ID_Vrach) values (20200004, 4)
insert into Vyzovy_and_Vrach(Kod_V_Vyzovy, ID_Vrach) values (20200005, 5)
insert into Smena_and_Tabel(Kod_Sm_Smena, Num_Tabel) values (101, 20201010001)
insert into Smena_and_Tabel(Kod_Sm_Smena, Num_Tabel) values (102, 20201010002)
insert into Smena_and_Tabel(Kod_Sm_Smena, Num_Tabel) values (103, 20201010003)
insert into Smena_and_Tabel(Kod_Sm_Smena, Num_Tabel) values (103, 20201010004)
insert into Smena_and_Tabel(Kod_Sm_Smena, Num_Tabel) values (104, 20201010005)