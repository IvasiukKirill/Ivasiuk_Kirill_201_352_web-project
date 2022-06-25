-- MySQL dump 10.13  Distrib 8.0.29, for Linux (x86_64)
--
-- Host: std-mysql    Database: std_1694_exam
-- ------------------------------------------------------
-- Server version	5.7.26-0ubuntu0.16.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `book_recives`
--

DROP TABLE IF EXISTS `book_recives`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `book_recives` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_book` int(11) NOT NULL,
  `id_users` int(11) NOT NULL,
  `mark` int(11) NOT NULL,
  `text` varchar(255) NOT NULL,
  `date_added` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  KEY `id_book` (`id_book`),
  KEY `id_users` (`id_users`),
  CONSTRAINT `book_recives_ibfk_1` FOREIGN KEY (`id_book`) REFERENCES `books` (`id`),
  CONSTRAINT `book_recives_ibfk_2` FOREIGN KEY (`id_users`) REFERENCES `users` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=29 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `book_recives`
--

LOCK TABLES `book_recives` WRITE;
/*!40000 ALTER TABLE `book_recives` DISABLE KEYS */;
INSERT INTO `book_recives` VALUES (23,45,7,5,'эту я читаю','2022-06-25 21:48:53'),(24,46,7,5,'собираюсь начать читать','2022-06-25 22:05:23'),(25,47,7,4,'после мураками прочту','2022-06-25 22:22:06'),(26,48,7,5,'Великолепная книга, будут трудности и барьеры со вхождением в мир этого произведения, но оно явно того стоит','2022-06-25 22:27:41'),(27,49,7,3,'Хороший приключенческий роман для охотников за сокровищами','2022-06-25 23:06:12'),(28,50,7,5,'Великолепный научно-фантастический роман','2022-06-25 23:12:11');
/*!40000 ALTER TABLE `book_recives` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `books`
--

DROP TABLE IF EXISTS `books`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `books` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name_book` varchar(225) NOT NULL,
  `short_description` text NOT NULL,
  `year` date NOT NULL,
  `publishing_house` varchar(25) NOT NULL,
  `author` varchar(225) NOT NULL,
  `volume` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=51 DEFAULT CHARSET=utf8 COMMENT='Описание книги';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `books`
--

LOCK TABLES `books` WRITE;
/*!40000 ALTER TABLE `books` DISABLE KEYS */;
INSERT INTO `books` VALUES (45,'Демиан','\"Демиан\" - это роман о борьбе с собственными демонами и Я взрослеющего человека, его поиском индивидуальности, описанный через символизм библейских мотивов (светлый/темный мир, Каин и Авель, Ева, Абраксас). Это роман-взросление, где мальчик, находясь в переходном возрасте, стремится показать себя, в нем произрастает бунт против школы, сверстников, родителей, учебы, режима и устоев.','1919-01-01','АСТ Москва','Герман Гессе',224),(46,'Норвежский лес','Действие происходит в Токио 1960-х годов, когда японские студенты вместе со студентами всего мира протестовали против установившегося порядка. Мураками занимают потери, которые каждый человек несёт с ходом жизни. Главный герой и рассказчик — Тоору Ватанабэ, который вспоминает свои былые дни в качестве студента одного из токийских колледжей. Посредством его воспоминаний читатель знакомится с развитием его отношений с двумя совершенно разными девушками — прекрасной, но психологически травмированной Наоко, и эмоциональной, живой Мидори.','1987-01-01','\"Э\"','Харуки Мураками',368),(47,'Книжный вор','Действие происходит в нацистской Германии начиная с января 1939 года. Повествование ведётся от лица Смерти. Главная героиня романа — девятилетняя Лизель Мемингер, становящаяся старше по мере развития сюжета. У Лизель нелёгкая судьба: её отец, неизвестным образом связанный с коммунистами, без вести пропал, а мать, не в силах ухаживать за девочкой и её братом, решает отдать детей на воспитание приёмным родителям, тем самым спасая её от преследования нацистских властей. По дороге к новому дому брат Лизель умирает, вероятно от пневмонии, что происходит прямо на глазах у девочки, оставляя тяжелое впечатление на всю жизнь. Брата Лизель хоронят на кладбище, где девочка и крадет свою первую в жизни книгу — «Наставления могильщикам».','2005-01-01','АСТ','Маркус Зусак',608),(48,'Цветы для Элджернона','Идеи рассказа формировались в течение 14 лет и были вдохновлены различными событиями из жизни Киза. Началось всё в 1945 году с его конфликта с родителями, которые настояли на прохождении им курсов для поступающих в медицинские вузы, вопреки его желанию стать писателем. Он почувствовал, что образование вбивает клин между ним и родителями, и это привело его к вопросу об увеличении интеллекта. Основные события произошли в 1957 году, когда Киз преподавал английский язык в школе для умственно отсталых детей; один из учеников спросил у него, сможет ли он перевестись в обычную школу, если будет старательно заниматься и станет умным.','1959-01-01','Эксмо','Дэниел Киз',320),(49,'Остров сокровищ','Роман шотландского писателя Роберта Стивенсона о приключениях, связанных с поиском сокровищ, спрятанных капитаном Флинтом на необитаемом острове.','1883-01-01','Лабиринт','Роберт Льюис Стивенсон',188),(50,'Двадцать тысяч лье под водой','Роман повествует о приключениях капитана Немо на построенной им подводной лодке «Наутилус» — технологическом чуде описываемого времени. Рассказ ведётся от первого лица, со слов профессора Музея естественной истории Пьера Аронакса[fr], одного из случайных пассажиров этой субмарины.','1869-01-01','Лабиринт','Жюль Верн',480);
/*!40000 ALTER TABLE `books` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `covers_books`
--

DROP TABLE IF EXISTS `covers_books`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `covers_books` (
  `id` varchar(100) NOT NULL,
  `file_name` varchar(100) NOT NULL,
  `mime_type` varchar(100) NOT NULL,
  `md5_hash` varchar(100) NOT NULL,
  `id_book` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `md5_hash` (`md5_hash`),
  KEY `id_book` (`id_book`),
  CONSTRAINT `covers_books_ibfk_1` FOREIGN KEY (`id_book`) REFERENCES `books` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `covers_books`
--

LOCK TABLES `covers_books` WRITE;
/*!40000 ALTER TABLE `covers_books` DISABLE KEYS */;
INSERT INTO `covers_books` VALUES ('15827d15-a212-4359-89d9-945cdc8304d8','11385314-1.jpg','image/jpeg','9ea6e91298274963b5f521d81f3d2834',48),('2fbaa3b9-5755-4294-9e93-58379062fedf','norwegian-wood.jpg','image/jpeg','b8139a1ee3f02b769393069ca1d29d37',46),('8056b2e0-fff9-4a4d-837c-d5d39a8d83e1','zusac.jpg','image/jpeg','97757286a765180ff28d5a9ee0738944',47),('8f66ccda-b7b3-4aa1-8d92-4b10d1bbb631','100023078312b0.jpg','image/jpeg','c6c2cca11e42dc2e3c8106f663836106',49),('b77556b2-cfbe-454a-a2d4-8f510db1e7d6','13397311_1_dvadtsat-tyisyach-le-pod-vodoj.jpg','image/jpeg','ee2a037b43766e745a7b36f60b54427a',50),('ed928bea-0074-4756-90a4-1f830ac765c8','demian.jpg','image/jpeg','7d672399f5b02a16f5c530deb38934b5',45);
/*!40000 ALTER TABLE `covers_books` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `genrys`
--

DROP TABLE IF EXISTS `genrys`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `genrys` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(25) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `genry` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8 COMMENT='Жанры книг';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `genrys`
--

LOCK TABLES `genrys` WRITE;
/*!40000 ALTER TABLE `genrys` DISABLE KEYS */;
INSERT INTO `genrys` VALUES (1,'Детектив'),(9,'Дизайн'),(2,'Драма'),(8,'Литература'),(6,'Мистика'),(4,'Приключения'),(3,'Роман'),(7,'Фантастика'),(5,'Фэнтези ');
/*!40000 ALTER TABLE `genrys` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `genrys_books`
--

DROP TABLE IF EXISTS `genrys_books`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `genrys_books` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_book` int(11) NOT NULL,
  `id_genry` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `id_book` (`id_book`),
  KEY `id_genry` (`id_genry`),
  CONSTRAINT `genrys_books_ibfk_1` FOREIGN KEY (`id_book`) REFERENCES `books` (`id`),
  CONSTRAINT `genrys_books_ibfk_2` FOREIGN KEY (`id_genry`) REFERENCES `genrys` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=75 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `genrys_books`
--

LOCK TABLES `genrys_books` WRITE;
/*!40000 ALTER TABLE `genrys_books` DISABLE KEYS */;
INSERT INTO `genrys_books` VALUES (61,45,3),(62,46,3),(64,48,7),(65,48,5),(68,47,2),(69,49,4),(70,49,3),(71,50,4),(72,50,3),(73,50,7),(74,50,5);
/*!40000 ALTER TABLE `genrys_books` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `roles`
--

DROP TABLE IF EXISTS `roles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `roles` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(25) NOT NULL,
  `description` text,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `roles`
--

LOCK TABLES `roles` WRITE;
/*!40000 ALTER TABLE `roles` DISABLE KEYS */;
INSERT INTO `roles` VALUES (1,'Администратор','суперпользователь, имеет полный доступ к системе, в том числе к созданию и удалению книг'),(2,'Модератор','может редактировать данные книг и производить модерацию рецензий'),(3,'Пользователь ','может оставлять рецензии');
/*!40000 ALTER TABLE `roles` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `login` varchar(25) NOT NULL,
  `first_name` varchar(25) NOT NULL,
  `last_name` varchar(25) NOT NULL,
  `middle_name` varchar(25) DEFAULT NULL,
  `role_id` int(11) DEFAULT NULL,
  `password_hash` varchar(256) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `login` (`login`),
  KEY `role_id` (`role_id`),
  CONSTRAINT `users_ibfk_1` FOREIGN KEY (`role_id`) REFERENCES `roles` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (7,'admin','Кирилл','Ивасюк','Евгеньевич',1,'pbkdf2:sha256:260000$qbLcys39eHKAICV9$d15521b693121733d81fafba61ad021b94909496e5404fb703a3ada1b9700f3b'),(17,'moderator','Иван','Николаев','Александрович',2,'pbkdf2:sha256:260000$qIMjRucDc5UXdiYB$c7556f919d7345eb352aa933a34faf8042c5632148eb8ae432618b0ceacf2b94'),(18,'nastya','Анастасия','Долгих','Батьковна',3,'pbkdf2:sha256:260000$0venXGzlTUP7jxDg$4d8bd97bf6fe9aa1bfabfef96a449443de9604af20f062aaea271e01755d2c04');
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-06-26  0:01:45
