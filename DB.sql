CREATE DATABASE  IF NOT EXISTS `webphonon` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `webphonon`;
-- MySQL dump 10.15  Distrib 10.0.21-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: webphonon
-- ------------------------------------------------------
-- Server version	10.0.21-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `actor`
--

DROP TABLE IF EXISTS `actor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `actor` (
  `actor_id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`actor_id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `album`
--

DROP TABLE IF EXISTS `album`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `album` (
  `album_id` int(11) NOT NULL AUTO_INCREMENT,
  `album_name` varchar(45) DEFAULT NULL,
  `record_label` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`album_id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `album_cast`
--

DROP TABLE IF EXISTS `album_cast`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `album_cast` (
  `album_cast_id` int(11) NOT NULL AUTO_INCREMENT,
  `album_id` int(11) DEFAULT NULL,
  `artist_id` int(11) DEFAULT NULL,
  `role` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`album_cast_id`),
  KEY `fk_album_cast_1_idx` (`artist_id`),
  KEY `fk_album_cast_2_idx` (`album_id`),
  CONSTRAINT `fk_album_cast_1` FOREIGN KEY (`artist_id`) REFERENCES `artist` (`artist_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_album_cast_2` FOREIGN KEY (`album_id`) REFERENCES `album` (`album_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `artist`
--

DROP TABLE IF EXISTS `artist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `artist` (
  `artist_id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`artist_id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `movie_cast`
--

DROP TABLE IF EXISTS `movie_cast`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `movie_cast` (
  `movie_cast_id` int(11) NOT NULL AUTO_INCREMENT,
  `movie_id` int(11) DEFAULT NULL,
  `actor_id` int(11) DEFAULT NULL,
  `charecter_name` varchar(45) DEFAULT NULL,
  `role` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`movie_cast_id`),
  KEY `fk_movie_cast_1_idx` (`movie_id`),
  KEY `fk_movie_cast_2_idx` (`actor_id`),
  CONSTRAINT `fk_movie_cast_1` FOREIGN KEY (`movie_id`) REFERENCES `movies` (`movies_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_movie_cast_2` FOREIGN KEY (`actor_id`) REFERENCES `actor` (`actor_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `movies`
--

DROP TABLE IF EXISTS `movies`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `movies` (
  `movies_id` int(11) NOT NULL AUTO_INCREMENT,
  `url` varchar(255) DEFAULT NULL,
  `title` varchar(45) DEFAULT NULL,
  `language` varchar(45) DEFAULT NULL,
  `studio` varchar(45) DEFAULT NULL,
  `rating` varchar(45) DEFAULT NULL,
  `genre` varchar(45) DEFAULT NULL,
  `year` int(11) DEFAULT NULL,
  PRIMARY KEY (`movies_id`),
  UNIQUE KEY `url_UNIQUE` (`url`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `music`
--

DROP TABLE IF EXISTS `music`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `music` (
  `music_id` int(11) NOT NULL AUTO_INCREMENT,
  `url` varchar(255) DEFAULT NULL,
  `title` varchar(45) DEFAULT NULL,
  `genre` varchar(45) DEFAULT NULL,
  `language` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`music_id`),
  UNIQUE KEY `url_UNIQUE` (`url`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `music_album`
--

DROP TABLE IF EXISTS `music_album`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `music_album` (
  `music_album_id` int(11) NOT NULL AUTO_INCREMENT,
  `album_id` int(11) DEFAULT NULL,
  `music_id` int(11) DEFAULT NULL,
  `track` int(11) DEFAULT NULL,
  PRIMARY KEY (`music_album_id`),
  KEY `fk_music_album_1_idx` (`album_id`),
  KEY `fk_music_album_2_idx` (`music_id`),
  CONSTRAINT `fk_music_album_1` FOREIGN KEY (`album_id`) REFERENCES `album` (`album_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_music_album_2` FOREIGN KEY (`music_id`) REFERENCES `music` (`music_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `music_video_cast`
--

DROP TABLE IF EXISTS `music_video_cast`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `music_video_cast` (
  `music_video_cast_id` int(11) NOT NULL AUTO_INCREMENT,
  `music_video_id` int(11) DEFAULT NULL,
  `actor_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`music_video_cast_id`),
  KEY `fk_music_video_cast_1_idx` (`music_video_id`),
  KEY `fk_music_video_cast_2_idx` (`actor_id`),
  CONSTRAINT `fk_music_video_cast_1` FOREIGN KEY (`music_video_id`) REFERENCES `music_videos` (`mv_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_music_video_cast_2` FOREIGN KEY (`actor_id`) REFERENCES `actor` (`actor_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `music_videos`
--

DROP TABLE IF EXISTS `music_videos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `music_videos` (
  `mv_id` int(11) NOT NULL AUTO_INCREMENT,
  `url` varchar(255) DEFAULT NULL,
  `music_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`mv_id`),
  UNIQUE KEY `url_UNIQUE` (`url`),
  KEY `fk_music_videos_1_idx` (`music_id`),
  CONSTRAINT `fk_music_videos_1` FOREIGN KEY (`music_id`) REFERENCES `music` (`music_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `tv`
--

DROP TABLE IF EXISTS `tv`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tv` (
  `tv_id` int(11) NOT NULL AUTO_INCREMENT,
  `url` varchar(255) NOT NULL,
  `title` varchar(45) DEFAULT NULL,
  `season` int(11) DEFAULT NULL,
  `episode` int(11) DEFAULT NULL,
  `ep_title` varchar(45) DEFAULT NULL,
  `language` varchar(45) DEFAULT NULL,
  `genre` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`tv_id`),
  UNIQUE KEY `url_UNIQUE` (`url`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `tv_cast`
--

DROP TABLE IF EXISTS `tv_cast`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tv_cast` (
  `tv_cast_id` int(11) NOT NULL AUTO_INCREMENT,
  `tv_id` int(11) DEFAULT NULL,
  `actor_id` int(11) DEFAULT NULL,
  `charecter_name` varchar(45) DEFAULT NULL,
  `role` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`tv_cast_id`),
  KEY `fk_tv_cast_1_idx` (`tv_id`),
  KEY `fk_tv_cast_2_idx` (`actor_id`),
  CONSTRAINT `fk_tv_cast_1` FOREIGN KEY (`tv_id`) REFERENCES `tv` (`tv_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_tv_cast_2` FOREIGN KEY (`actor_id`) REFERENCES `actor` (`actor_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-01-30  0:51:57
