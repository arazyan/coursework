-- Создание сущностей

CREATE TABLE adjectives
( 
    id BIGSERIAL PRIMARY KEY,
    ru VARCHAR(200) NULL DEFAULT '',
    en VARCHAR(200) NULL DEFAULT ''
);

CREATE TABLE nouns
(
    id BIGSERIAL PRIMARY KEY,
    ru VARCHAR(200) NULL DEFAULT '',
    en VARCHAR(200) NULL DEFAULT ''
);

CREATE TABLE others
( 
    id BIGSERIAL PRIMARY KEY,
    ru VARCHAR(200) NULL DEFAULT '',
    en VARCHAR(200) NULL DEFAULT ''
);

CREATE TABLE verbs
( 
    id BIGSERIAL PRIMARY KEY,
    ru VARCHAR(200) NULL DEFAULT '',
    en VARCHAR(200) NULL DEFAULT ''
);

-- Заполнение данными (см. папку "etc")
-- PostgreSQL команды

\COPY adjectives(ru, en) FROM 'C:\Users\Public\ready_adjectives.csv'
DELIMITER ',' CSV HEADER;

\COPY nouns(ru, en) FROM 'C:\Users\Public\ready_nouns.csv'
DELIMITER ',' CSV HEADER;

\COPY others(ru, en) FROM 'C:\Users\Public\ready_others.csv'
DELIMITER ',' CSV HEADER;

\COPY verbs(ru, en) FROM 'C:\Users\Public\ready_verbs.csv'
DELIMITER ',' CSV HEADER;

CREATE INDEX adjectives_idx_ru ON adjectives(ru);
CREATE INDEX adjectives_idx_en ON adjectives(en);

CREATE INDEX nouns_idx_ru ON nouns(ru);
CREATE INDEX nouns_idx_en ON nouns(en);

CREATE INDEX others_idx_ru ON others(ru);
CREATE INDEX others_idx_en ON others(en);

CREATE INDEX verbs_idx_ru ON verbs(ru);
CREATE INDEX verbs_idx_en ON verbs(en);