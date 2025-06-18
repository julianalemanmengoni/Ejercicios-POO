CREATE DATABASE IF NOT EXISTS poo;
USE poo;

CREATE TABLE IF NOT EXISTS usuarios (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(50),
    apellido VARCHAR(50),
    usuario VARCHAR(50),
    clave VARCHAR(50),
    mail VARCHAR(100)
);

INSERT INTO usuarios (nombre, apellido, usuario, clave, mail) VALUES
('Ana', 'Pérez', 'ana', '1234', 'ana@mail.com'),
('Luis', 'Gómez', 'luis', 'abcd', 'luis@mail.com'),
('María', 'López', 'maria', 'pass', 'maria@mail.com');
