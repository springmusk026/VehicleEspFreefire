////****Vehicle****//////

struct v_t {
    void *object;
    Vector3 location;
    int health;
};
class VehicleManager {
public:
    std::vector<v_t *> *enemies;

    VehicleManager() {
        enemies = new std::vector<v_t *>();
    }

    bool isEnemyPresent(void *enemyObject) {
        for (std::vector<v_t *>::iterator it = enemies->begin(); it != enemies->end(); it++) {
            if ((*it)->object == enemyObject) {
                return true;
            }
        }

        return false;
    }

    void removeEnemy(v_t *enemy) {
        for (int i = 0; i < enemies->size(); i++) {
            if ((*enemies)[i] == enemy) {
                enemies->erase(enemies->begin() + i);

                return;
            }
        }
    }

    void tryAddEnemy(void *enemyObject) {
        if (isEnemyPresent(enemyObject)) {
            return;
        }


        v_t *newEnemy = new v_t();

        newEnemy->object = enemyObject;

        enemies->push_back(newEnemy);
    }

    void updateEnemies(void *enemyObject) {
        for (int i = 0; i < enemies->size(); i++) {
            v_t *current = (*enemies)[i];


        }
    }

};
VehicleManager *vehicleManager;

