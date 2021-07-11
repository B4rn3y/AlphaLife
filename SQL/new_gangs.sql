
USE `altislifetest`;

DROP PROCEDURE IF EXISTS `deleteOldGangs`;

ALTER TABLE `vehicles` ADD `gang_id` INT NOT NULL DEFAULT '-1' AFTER `active`;

DROP TABLE IF EXISTS `gangs`;
CREATE TABLE IF NOT EXISTS `gangs` (
    `id`          INT NOT NULL AUTO_INCREMENT,
    `name`        VARCHAR(32) DEFAULT NULL,
    `tag`         VARCHAR(32) DEFAULT NULL,
    `alliances`   text NOT NULL DEFAULT '"[]"',
    `maxmembers`  INT NOT NULL DEFAULT 8,
    `bank`        INT NOT NULL DEFAULT 0,
    `tax`         INT NOT NULL DEFAULT 0,
    `public`      TINYINT NOT NULL DEFAULT 0,
    `insert_time` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `last_seen` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

    PRIMARY KEY (`id`),
    UNIQUE KEY `unique_name` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

DROP TABLE IF EXISTS`gang_members`;
CREATE TABLE IF NOT EXISTS `gang_members` (
    `id`          INT NOT NULL AUTO_INCREMENT,
    `gang_id`     INT NOT NULL,
    `pid`         VARCHAR(17) NOT NULL,
    `leader`       TINYINT NOT NULL DEFAULT 0,
    `right_invite` TINYINT NOT NULL DEFAULT 0,
    `right_expand` TINYINT NOT NULL DEFAULT 0,
    `right_withdraw` TINYINT NOT NULL DEFAULT 0,
    `right_skins` TINYINT NOT NULL DEFAULT 0,
    `right_kick` TINYINT NOT NULL DEFAULT 0,
    `right_house` TINYINT NOT NULL DEFAULT 0,
    `right_garage` TINYINT NOT NULL DEFAULT 0,
    `insert_time` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `last_seen` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;



SELECT gang_members.gang_id,players.name, gang_members.pid, gang_members.leader, gang_members.right_invite, gang_members.right_expand, gang_members.right_withdraw, gang_members.right_skins, gang_members.right_kick FROM gang_members LEFT JOIN players ON gang_members.pid = players.pid where gang_members.pid = '76561198018512569';

SELECT name, pid
FROM players, gang_members
WHERE gang_members.pid = players.pid
GROUP BY pid
