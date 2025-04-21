# 📌 Comunicare între procese

Acest proiect reprezintă o aplicație scrisă în limbajul C care exemplifică comunicarea între procese. Este util pentru învățarea conceptelor de bază despre procese și modalitățile prin care acestea pot colabora în cadrul unui sistem de operare.

---

## 🧠 Descriere

Programul ilustrează cum două procese pot comunica între ele folosind mecanisme specifice precum `pipe`, `fork` și `wait`. Procesul părinte creează un proces copil și trimite sau primește informații de la acesta. Este un exemplu didactic, ideal pentru laboratoarele sau proiectele de la cursurile de Sisteme de Operare.

---

## 💻 Tehnologii utilizate

- Limbaj: C
- Platformă recomandată: Linux
- Compilator: `gcc`

---

## 📋 Instrucțiuni de instalare și utilizare

1. Clonați repository-ul pe computerul vostru:
   ```bash
   git clone https://github.com/regep-raluca/comunicare-intre-procese.git
2. Accesați directorul proiectului:
   ```bash
   cd comunicare_intre_procese
3. Compilați fișierul principal comunicare_intre_procese.c:
   ```bash
   gcc comunicare_intre_procese.c -o comunicare_intre_procese
4. Rulați aplicația:
   ```bash
   ./comunicare_intre_procese
---

## 🛠️ Funcționalități
- **Comunicare între procese**: Utilizează semnale pentru a trimite mesaje între procese.
- **Sincronizare**: Procesele sunt sincronizate pentru a asigura o execuție corectă a fluxului de date.
---

## 💡 Exemplu de utilizare

Pentru a rula aplicația, urmați pașii din secțiunea "Instrucțiuni de instalare și utilizare". După rularea aplicației, procesul părinte și procesul copil vor comunica între ele folosind semnale, iar fluxul de date va fi sincronizat pentru a evita orice erori de execuție.

---

## ⚙️ Explicație detaliată a funcționalităților

### 1. **pipe**
`pipe` este un mecanism de comunicare unidirecțională între procese. În acest proiect, `pipe` este folosit pentru a transmite date între procesul părinte și procesul copil.

### 2. **fork**
`fork` creează un nou proces, copierea procesului curent. Acesta este folosit pentru a crea procesul copil.

### 3. **wait**
`wait` este folosit pentru a aștepta terminarea procesului copil înainte de a continua execuția procesului părinte. Astfel se asigură sincronizarea între cele două procese.

---

## 🐞 Depanare

În cazul în care întâmpinați probleme la rularea programului, verificați următoarele:

- Asigurați-vă că utilizați un sistem de operare bazat pe Linux.
- Verificați dacă aveți permisiuni corespunzătoare pentru a rula fișierele executabile.
- Asigurați-vă că ați compilat corect fișierul sursă cu `gcc`.

Dacă problema persistă, nu ezitați să deschideți un **Issue** în repository-ul nostru.

---

## 📄 Licență

Distribuit sub licența MIT. Vedeți [LICENSE](LICENSE) pentru mai multe informații.
