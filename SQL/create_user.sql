CREATE USER 'guardian'@'localhost' IDENTIFIED BY '';
CREATE USER 'guardian'@'%' IDENTIFIED BY '';


GRANT Select, Update  ON `altislife`.`players` TO 'guardian'@'localhost';
GRANT Select, Update  ON `altislife`.`players` TO 'guardian'@'%';

GRANT Select, Update  ON `altislife`.`containers` TO 'guardian'@'localhost';
GRANT Select, Update  ON `altislife`.`containers` TO 'guardian'@'%';


GRANT Select, Update  ON `altislife`.`evidence_room` TO 'guardian'@'localhost';
GRANT Select, Update  ON `altislife`.`evidence_room` TO 'guardian'@'%';

GRANT Select, Update  ON `altislife`.`gangs` TO 'guardian'@'localhost';
GRANT Select, Update  ON `altislife`.`gangs` TO 'guardian'@'%';

GRANT Select, Update  ON `altislife`.`houses` TO 'guardian'@'localhost';
GRANT Select, Update  ON `altislife`.`houses` TO 'guardian'@'%';

GRANT Select, Update  ON `altislife`.`vehicles` TO 'guardian'@'localhost';
GRANT Select, Update  ON `altislife`.`vehicles` TO 'guardian'@'%';

GRANT Select, Update  ON `altislife`.`wanted` TO 'guardian'@'localhost';
GRANT Select, Update  ON `altislife`.`wanted` TO 'guardian'@'%';