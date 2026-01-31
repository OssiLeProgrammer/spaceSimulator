# Space Simulator

Dieses Projekt ist ein **Weltraum‑Simulator** (engl. *Space Simulator*), der die Bewegung und Darstellung eines Planetensystems in einer 3D‑Umgebung simuliert. Ziel ist es, die Zusammenarbeit von **Mathematik**, **Physik** und **Informatik** praktisch umzusetzen und visuell darzustellen.

## Verwendete Konzepte

### Mathematik

Mathematische Grundlagen bilden das Fundament der Simulation:

* **Vektoren** beschreiben die Position, Skalierung und Bewegungsrichtung der Planeten.
* **Matrizen** werden verwendet, um Transformationen wie Rotation, Verschiebung und Perspektive umzusetzen und die Planeten korrekt aus Sicht der Kamera darzustellen.

### Physik

Die zeitliche Entwicklung des Planetensystems basiert auf physikalischen Modellen:

* Die Bewegung der Planeten wird mithilfe physikalischer Gesetze beschrieben.
* Änderungen über die Zeit werden berechnet und in darstellbare Werte für die Simulation umgewandelt.

### Informatik

Die Umsetzung erfolgt mithilfe moderner Grafik‑ und Programmierkonzepte:

* Eine **Grafikbibliothek** verarbeitet die notwendigen Daten zur Darstellung der 3D‑Szene.
* Die dreidimensionalen Objekte werden durch mehrere **Daten‑Transformationen** in die Perspektive des Betrachters (Kamera) überführt.
* Dafür kommen **Shader** zum Einsatz – Programme, die direkt auf der GPU laufen und für die Darstellung zuständig sind.
* Die Kameralogik ist in einer separaten **Camera‑Bibliothek (Camera.h)** implementiert.
* Der Aufbau der Planeten sowie deren physikalische Eigenschaften sind in **Physics.h** definiert.

Dieses Projekt zeigt anschaulich, wie theoretische Konzepte aus verschiedenen Fachbereichen zusammenwirken, um eine interaktive 3D‑Simulation zu ermöglichen.
<img width="800" height="629" alt="Screenshot (183)" src="https://github.com/user-attachments/assets/9614f5ec-60d1-4555-89f8-8ef2259be337" />
