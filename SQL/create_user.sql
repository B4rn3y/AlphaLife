CREATE USER 'supporter'@'localhost' IDENTIFIED BY '';
CREATE USER 'supporter'@'%' IDENTIFIED BY '';


GRANT Select, UPDATE(`name`,`bankacc`,`civ_licenses`)  ON `altislife`.`players` TO 'supporter'@'localhost';
GRANT Select, UPDATE(`name`,`bankacc`,`civ_licenses`)  ON `altislife`.`players` TO 'supporter'@'%';