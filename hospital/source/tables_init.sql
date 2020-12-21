create table Smena(Kod_Sm integer primary key autoincrement, Coeff_2 float not null, Data_S date not null)
create table Specializacia(Kod_Sp integer primary key autoincrement, Name_type nchar(100) not null, Oklad integer not null)
create table Vziskania(Kod_Vz integer primary key, Name_type nchar(100) not null, Summa integer not null)
create table Vyzovy(Kod_V integer primary key autoincrement, Data date not null, Nadbavka integer not null)
create table Stazh(Kod_S integer primary key autoincrement, Obrazovanie varchar(100) not null, Opyt nchar(100) not null, Coeff_1 float not null)
create table Tabel(Num integer primary key, Kolvo_chasov integer not null)
create table ZpVedomost(Kod_Z integer primary key autoincrement, coeff_experience integer default 1, coeff_shifts default 1, increase integer default 0, Vyplata_oklad integer not null, Vyplata_gen integer default 0)
create table Vrach(ID integer primary key autoincrement, Kod_Z_ZpVedomost integer references ZpVedomost(Kod_Z), Kod_S_Stazh integer references Stazh(Kod_S),FIO varchar(100) not null, Kfalifikacia nchar(100) not null)
create table Smena_and_Vrach(Kod_Sm_Smena integer references Smena(Kod_Sm),ID_Vrach integer references Vrach(ID))
create table Specializacia_and_Vrach(Kod_Sp_Specializacia integer references Specializacia(Kod_Sp),ID_Vrach integer references Vrach(ID))
create table Vziskania_and_Vrach(Kod_Vz_Vziskania integer references Vziskania(Kod_Vz),ID_Vrach integer references Vrach(ID))
create table Vyzovy_and_Vrach(Kod_V_Vyzovy integer references Vyzovy(Kod_V),ID_Vrach integer references Vrach(ID))
create table Smena_and_Tabel(Kod_Sm_Smena integer references Smena(Kod_Sm),Num_Tabel integer references Tabel(Num))
create table Current_values(coeff float default 1, increase int default 0)
insert into Current_values values (1, 0)