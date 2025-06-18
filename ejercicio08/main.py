from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
import mysql.connector

app = FastAPI()

class LoginRequest(BaseModel):
    usuario: str
    clave: str

def get_db_connection():
    return mysql.connector.connect(
        host="localhost",
        user="root",
        password="tu_clave",
        database="poo"
    )

@app.post("/auth/login")
def login(data: LoginRequest):
    conn = get_db_connection()
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM usuarios WHERE usuario=%s AND clave=%s", (data.usuario, data.clave))
    user = cursor.fetchone()
    cursor.close()
    conn.close()

    if user:
        return {"mensaje": "Login exitoso"}
    else:
        raise HTTPException(status_code=401, detail="Credenciales incorrectas")
