

USE `altislife`;


ALTER TABLE `vehicles` ADD `material` INT NOT NULL DEFAULT '-1' AFTER `color`;
ALTER TABLE `vehicles` ADD `horn` INT NOT NULL DEFAULT '-1' AFTER `material`;
ALTER TABLE `vehicles` ADD `nitro` INT NOT NULL DEFAULT '-1' AFTER `horn`;
ALTER TABLE `vehicles` ADD `oil` INT NOT NULL DEFAULT '-1' AFTER `nitro`;
ALTER TABLE `vehicles` ADD `light` INT NOT NULL DEFAULT '-1' AFTER `oil`;
ALTER TABLE `vehicles` ADD `insure` TINYINT(1) NOT NULL DEFAULT '0' AFTER `light`;