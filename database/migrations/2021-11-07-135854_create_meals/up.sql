-- Your SQL goes here
CREATE TABLE meals (
  id SERIAL PRIMARY KEY,
  date DATE NOT NULL,
  value TEXT NOT NULL,
  menu_id SERIAL NOT NULL,
  FOREIGN KEY (menu_id) REFERENCES menus(id) ON DELETE CASCADE,
  UNIQUE (date, menu_id, value)
);