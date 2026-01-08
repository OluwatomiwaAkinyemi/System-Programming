# System-Programming
System Programming Project

This repository contains our System Programming project completed as part of our coursework at Fenerbahçe University – Computer Engineering Department.
The project involves implementing core system-level programming concepts using C++, focusing on performance, process management, memory, and low-level operations.

👥 Project Team

Project Manager / Team Lead & C++ Developer
	•	Oluwatomiwa Micheal Akinyemi — Student ID: 220304148

Docker & DevOps Engineer / C++ Developer
	•	Waren Moudoumi Moustafa Konate — Student ID: 220304142


## 🐳 Docker Hub Repositories
The Docker images for this project are publicly available:

| Component | Docker Hub Link | Command to Pull |
|-----------|-----------------|-----------------|
| **C++ Application** | [sysprog-app](https://hub.docker.com/r/warenstu/sysprog-app) | `docker pull warenstu/sysprog-app:latest` |
| **Database** | [sysprog-db](https://hub.docker.com/r/warenstu/sysprog-db) | `docker pull warenstu/sysprog-db:latest` |


https://hub.docker.com/r/warenstu/sysprog-app

## Project Management
* **Project Board:** [View Board Here](https://github.com/users/warenmouss/projects/1)


## Phase 4: Kubernetes Migration (Week 4)

In the final phase, the application was migrated from local Docker Compose to a Kubernetes cluster using Minikube.

### Key Features
* **Orchestration:** Managed via Minikube (v1.37.0).
* **Deployment:**
    * `postgres-deployment.yaml`: Stateful database set up with persistent volumes.
    * `app-deployment.yaml`: Stateless C++ application.
* **Service Discovery:** The app connects to the DB using the internal Kubernetes DNS name `postgres-service`.
* **Scalability:** The application was successfully scaled to 3 replicas to demonstrate load distribution.

### How to Run (Kubernetes)
1. Start Minikube: `minikube start`
2. Deploy Database: `kubectl apply -f k8s/postgres-deployment.yaml` & `kubectl apply -f k8s/postgres-service.yaml`
3. Deploy App: `kubectl apply -f k8s/app-deployment.yaml` & `kubectl apply -f k8s/app-service.yaml`
4. Access App: `minikube service sysprog-service` 
