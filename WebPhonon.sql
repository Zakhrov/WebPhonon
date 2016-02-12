--
-- PostgreSQL database dump
--

-- Dumped from database version 9.4.5
-- Dumped by pg_dump version 9.4.5
-- Started on 2016-02-12 20:47:27 IST

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

DROP DATABASE webphonon;
--
-- TOC entry 2744 (class 1262 OID 16404)
-- Name: webphonon; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE webphonon WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'en_US.UTF-8' LC_CTYPE = 'en_US.UTF-8';


ALTER DATABASE webphonon OWNER TO postgres;

\connect webphonon

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

--
-- TOC entry 5 (class 2615 OID 2200)
-- Name: public; Type: SCHEMA; Schema: -; Owner: postgres
--

CREATE SCHEMA public;


ALTER SCHEMA public OWNER TO postgres;

--
-- TOC entry 2745 (class 0 OID 0)
-- Dependencies: 5
-- Name: SCHEMA public; Type: COMMENT; Schema: -; Owner: postgres
--

COMMENT ON SCHEMA public IS 'standard public schema';


--
-- TOC entry 198 (class 3079 OID 12467)
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- TOC entry 2747 (class 0 OID 0)
-- Dependencies: 198
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


--
-- TOC entry 199 (class 3079 OID 16393)
-- Name: fuzzystrmatch; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS fuzzystrmatch WITH SCHEMA public;


--
-- TOC entry 2748 (class 0 OID 0)
-- Dependencies: 199
-- Name: EXTENSION fuzzystrmatch; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION fuzzystrmatch IS 'determine similarities and distance between strings';


SET search_path = public, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = true;

--
-- TOC entry 173 (class 1259 OID 16481)
-- Name: actor; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE actor (
    actor_id integer NOT NULL,
    name character varying
);


ALTER TABLE actor OWNER TO postgres;

--
-- TOC entry 172 (class 1259 OID 16479)
-- Name: actor_actor_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE actor_actor_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE actor_actor_id_seq OWNER TO postgres;

--
-- TOC entry 2749 (class 0 OID 0)
-- Dependencies: 172
-- Name: actor_actor_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE actor_actor_id_seq OWNED BY actor.actor_id;


--
-- TOC entry 175 (class 1259 OID 16495)
-- Name: album; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE album (
    album_id integer NOT NULL,
    album_name character varying,
    record_label character varying
);


ALTER TABLE album OWNER TO postgres;

--
-- TOC entry 174 (class 1259 OID 16493)
-- Name: album_album_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE album_album_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE album_album_id_seq OWNER TO postgres;

--
-- TOC entry 2750 (class 0 OID 0)
-- Dependencies: 174
-- Name: album_album_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE album_album_id_seq OWNED BY album.album_id;


--
-- TOC entry 177 (class 1259 OID 16510)
-- Name: album_cast; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE album_cast (
    album_cast_id integer NOT NULL,
    album_id integer,
    artist_id integer,
    role character varying
);


ALTER TABLE album_cast OWNER TO postgres;

--
-- TOC entry 176 (class 1259 OID 16508)
-- Name: album_cast_album_cast_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE album_cast_album_cast_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE album_cast_album_cast_id_seq OWNER TO postgres;

--
-- TOC entry 2751 (class 0 OID 0)
-- Dependencies: 176
-- Name: album_cast_album_cast_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE album_cast_album_cast_id_seq OWNED BY album_cast.album_cast_id;


--
-- TOC entry 179 (class 1259 OID 16526)
-- Name: artist; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE artist (
    artist_id integer NOT NULL,
    name character varying
);


ALTER TABLE artist OWNER TO postgres;

--
-- TOC entry 178 (class 1259 OID 16524)
-- Name: artist_artist_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE artist_artist_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE artist_artist_id_seq OWNER TO postgres;

--
-- TOC entry 2752 (class 0 OID 0)
-- Dependencies: 178
-- Name: artist_artist_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE artist_artist_id_seq OWNED BY artist.artist_id;


--
-- TOC entry 181 (class 1259 OID 16540)
-- Name: movie_cast; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE movie_cast (
    movie_cast_id integer NOT NULL,
    movie_id integer,
    actor_id integer,
    charecter_name character varying,
    role character varying
);


ALTER TABLE movie_cast OWNER TO postgres;

--
-- TOC entry 180 (class 1259 OID 16538)
-- Name: movie_cast_movie_cast_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE movie_cast_movie_cast_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE movie_cast_movie_cast_id_seq OWNER TO postgres;

--
-- TOC entry 2753 (class 0 OID 0)
-- Dependencies: 180
-- Name: movie_cast_movie_cast_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE movie_cast_movie_cast_id_seq OWNED BY movie_cast.movie_cast_id;


--
-- TOC entry 183 (class 1259 OID 16557)
-- Name: movies; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE movies (
    movies_id integer NOT NULL,
    url text NOT NULL,
    title character varying,
    language character varying,
    studio character varying,
    rating character varying,
    genre character varying,
    year integer
);


ALTER TABLE movies OWNER TO postgres;

--
-- TOC entry 182 (class 1259 OID 16555)
-- Name: movies_movies_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE movies_movies_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE movies_movies_id_seq OWNER TO postgres;

--
-- TOC entry 2754 (class 0 OID 0)
-- Dependencies: 182
-- Name: movies_movies_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE movies_movies_id_seq OWNED BY movies.movies_id;


--
-- TOC entry 185 (class 1259 OID 16579)
-- Name: music; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE music (
    music_id integer NOT NULL,
    url text NOT NULL,
    title character varying,
    genre character varying,
    language character varying
);


ALTER TABLE music OWNER TO postgres;

--
-- TOC entry 187 (class 1259 OID 16598)
-- Name: music_album; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE music_album (
    music_album_id integer NOT NULL,
    album_id integer,
    music_id integer,
    track integer
);


ALTER TABLE music_album OWNER TO postgres;

--
-- TOC entry 186 (class 1259 OID 16596)
-- Name: music_album_music_album_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE music_album_music_album_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE music_album_music_album_id_seq OWNER TO postgres;

--
-- TOC entry 2755 (class 0 OID 0)
-- Dependencies: 186
-- Name: music_album_music_album_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE music_album_music_album_id_seq OWNED BY music_album.music_album_id;


--
-- TOC entry 184 (class 1259 OID 16577)
-- Name: music_music_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE music_music_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE music_music_id_seq OWNER TO postgres;

--
-- TOC entry 2756 (class 0 OID 0)
-- Dependencies: 184
-- Name: music_music_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE music_music_id_seq OWNED BY music.music_id;


--
-- TOC entry 189 (class 1259 OID 16611)
-- Name: music_video_cast; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE music_video_cast (
    music_video_cast_id integer NOT NULL,
    music_video_id integer,
    actor_id integer
);


ALTER TABLE music_video_cast OWNER TO postgres;

--
-- TOC entry 188 (class 1259 OID 16609)
-- Name: music_video_cast_music_video_cast_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE music_video_cast_music_video_cast_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE music_video_cast_music_video_cast_id_seq OWNER TO postgres;

--
-- TOC entry 2757 (class 0 OID 0)
-- Dependencies: 188
-- Name: music_video_cast_music_video_cast_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE music_video_cast_music_video_cast_id_seq OWNED BY music_video_cast.music_video_cast_id;


--
-- TOC entry 191 (class 1259 OID 16623)
-- Name: music_videos; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE music_videos (
    mv_id integer NOT NULL,
    url text NOT NULL,
    music_id integer
);


ALTER TABLE music_videos OWNER TO postgres;

--
-- TOC entry 190 (class 1259 OID 16621)
-- Name: music_videos_mv_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE music_videos_mv_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE music_videos_mv_id_seq OWNER TO postgres;

--
-- TOC entry 2758 (class 0 OID 0)
-- Dependencies: 190
-- Name: music_videos_mv_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE music_videos_mv_id_seq OWNED BY music_videos.mv_id;


--
-- TOC entry 193 (class 1259 OID 16640)
-- Name: music_view; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE music_view (
    music_video_cast_id integer NOT NULL,
    music_id integer,
    actor_id integer
);


ALTER TABLE music_view OWNER TO postgres;

--
-- TOC entry 192 (class 1259 OID 16638)
-- Name: music_view_music_video_cast_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE music_view_music_video_cast_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE music_view_music_video_cast_id_seq OWNER TO postgres;

--
-- TOC entry 2759 (class 0 OID 0)
-- Dependencies: 192
-- Name: music_view_music_video_cast_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE music_view_music_video_cast_id_seq OWNED BY music_view.music_video_cast_id;


--
-- TOC entry 195 (class 1259 OID 16652)
-- Name: tv; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE tv (
    tv_id integer NOT NULL,
    url text NOT NULL,
    title character varying,
    season integer,
    episode integer,
    ep_title character varying,
    language character varying,
    genre character varying
);


ALTER TABLE tv OWNER TO postgres;

--
-- TOC entry 197 (class 1259 OID 16674)
-- Name: tv_cast; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE tv_cast (
    tv_cast_id integer NOT NULL,
    tv_id integer,
    actor_id integer,
    charecter_name character varying,
    role character varying
);


ALTER TABLE tv_cast OWNER TO postgres;

--
-- TOC entry 196 (class 1259 OID 16672)
-- Name: tv_cast_tv_cast_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE tv_cast_tv_cast_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE tv_cast_tv_cast_id_seq OWNER TO postgres;

--
-- TOC entry 2760 (class 0 OID 0)
-- Dependencies: 196
-- Name: tv_cast_tv_cast_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE tv_cast_tv_cast_id_seq OWNED BY tv_cast.tv_cast_id;


--
-- TOC entry 194 (class 1259 OID 16650)
-- Name: tv_tv_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE tv_tv_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE tv_tv_id_seq OWNER TO postgres;

--
-- TOC entry 2761 (class 0 OID 0)
-- Dependencies: 194
-- Name: tv_tv_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE tv_tv_id_seq OWNED BY tv.tv_id;


--
-- TOC entry 2584 (class 2604 OID 16484)
-- Name: actor_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY actor ALTER COLUMN actor_id SET DEFAULT nextval('actor_actor_id_seq'::regclass);


--
-- TOC entry 2585 (class 2604 OID 16498)
-- Name: album_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY album ALTER COLUMN album_id SET DEFAULT nextval('album_album_id_seq'::regclass);


--
-- TOC entry 2586 (class 2604 OID 16513)
-- Name: album_cast_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY album_cast ALTER COLUMN album_cast_id SET DEFAULT nextval('album_cast_album_cast_id_seq'::regclass);


--
-- TOC entry 2587 (class 2604 OID 16529)
-- Name: artist_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY artist ALTER COLUMN artist_id SET DEFAULT nextval('artist_artist_id_seq'::regclass);


--
-- TOC entry 2588 (class 2604 OID 16543)
-- Name: movie_cast_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY movie_cast ALTER COLUMN movie_cast_id SET DEFAULT nextval('movie_cast_movie_cast_id_seq'::regclass);


--
-- TOC entry 2589 (class 2604 OID 16560)
-- Name: movies_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY movies ALTER COLUMN movies_id SET DEFAULT nextval('movies_movies_id_seq'::regclass);


--
-- TOC entry 2590 (class 2604 OID 16582)
-- Name: music_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY music ALTER COLUMN music_id SET DEFAULT nextval('music_music_id_seq'::regclass);


--
-- TOC entry 2591 (class 2604 OID 16601)
-- Name: music_album_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY music_album ALTER COLUMN music_album_id SET DEFAULT nextval('music_album_music_album_id_seq'::regclass);


--
-- TOC entry 2592 (class 2604 OID 16614)
-- Name: music_video_cast_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY music_video_cast ALTER COLUMN music_video_cast_id SET DEFAULT nextval('music_video_cast_music_video_cast_id_seq'::regclass);


--
-- TOC entry 2593 (class 2604 OID 16626)
-- Name: mv_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY music_videos ALTER COLUMN mv_id SET DEFAULT nextval('music_videos_mv_id_seq'::regclass);


--
-- TOC entry 2594 (class 2604 OID 16643)
-- Name: music_video_cast_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY music_view ALTER COLUMN music_video_cast_id SET DEFAULT nextval('music_view_music_video_cast_id_seq'::regclass);


--
-- TOC entry 2595 (class 2604 OID 16655)
-- Name: tv_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY tv ALTER COLUMN tv_id SET DEFAULT nextval('tv_tv_id_seq'::regclass);


--
-- TOC entry 2596 (class 2604 OID 16677)
-- Name: tv_cast_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY tv_cast ALTER COLUMN tv_cast_id SET DEFAULT nextval('tv_cast_tv_cast_id_seq'::regclass);


--
-- TOC entry 2598 (class 2606 OID 16489)
-- Name: actor_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY actor
    ADD CONSTRAINT actor_pkey PRIMARY KEY (actor_id);


--
-- TOC entry 2602 (class 2606 OID 16518)
-- Name: album_cast_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY album_cast
    ADD CONSTRAINT album_cast_pkey PRIMARY KEY (album_cast_id);


--
-- TOC entry 2600 (class 2606 OID 16503)
-- Name: album_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY album
    ADD CONSTRAINT album_pkey PRIMARY KEY (album_id);


--
-- TOC entry 2604 (class 2606 OID 16534)
-- Name: artist_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY artist
    ADD CONSTRAINT artist_pkey PRIMARY KEY (artist_id);


--
-- TOC entry 2606 (class 2606 OID 16548)
-- Name: movie_cast_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY movie_cast
    ADD CONSTRAINT movie_cast_pkey PRIMARY KEY (movie_cast_id);


--
-- TOC entry 2608 (class 2606 OID 16565)
-- Name: movies_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY movies
    ADD CONSTRAINT movies_pkey PRIMARY KEY (movies_id);


--
-- TOC entry 2610 (class 2606 OID 16567)
-- Name: movies_url_key; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY movies
    ADD CONSTRAINT movies_url_key UNIQUE (url);


--
-- TOC entry 2616 (class 2606 OID 16603)
-- Name: music_album_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY music_album
    ADD CONSTRAINT music_album_pkey PRIMARY KEY (music_album_id);


--
-- TOC entry 2612 (class 2606 OID 16587)
-- Name: music_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY music
    ADD CONSTRAINT music_pkey PRIMARY KEY (music_id);


--
-- TOC entry 2614 (class 2606 OID 16589)
-- Name: music_url_key; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY music
    ADD CONSTRAINT music_url_key UNIQUE (url);


--
-- TOC entry 2618 (class 2606 OID 16616)
-- Name: music_video_cast_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY music_video_cast
    ADD CONSTRAINT music_video_cast_pkey PRIMARY KEY (music_video_cast_id);


--
-- TOC entry 2620 (class 2606 OID 16631)
-- Name: music_videos_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY music_videos
    ADD CONSTRAINT music_videos_pkey PRIMARY KEY (mv_id);


--
-- TOC entry 2622 (class 2606 OID 16633)
-- Name: music_videos_url_key; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY music_videos
    ADD CONSTRAINT music_videos_url_key UNIQUE (url);


--
-- TOC entry 2624 (class 2606 OID 16645)
-- Name: music_view_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY music_view
    ADD CONSTRAINT music_view_pkey PRIMARY KEY (music_video_cast_id);


--
-- TOC entry 2630 (class 2606 OID 16682)
-- Name: tv_cast_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY tv_cast
    ADD CONSTRAINT tv_cast_pkey PRIMARY KEY (tv_cast_id);


--
-- TOC entry 2626 (class 2606 OID 16660)
-- Name: tv_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY tv
    ADD CONSTRAINT tv_pkey PRIMARY KEY (tv_id);


--
-- TOC entry 2628 (class 2606 OID 16662)
-- Name: tv_url_key; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY tv
    ADD CONSTRAINT tv_url_key UNIQUE (url);


--
-- TOC entry 2746 (class 0 OID 0)
-- Dependencies: 5
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


-- Completed on 2016-02-12 20:47:27 IST

--
-- PostgreSQL database dump complete
--

