



#include <pthread.h>

struct station { //we have two main elements, train and passengers
    //how many passengers on the train??

	pthread_mutex_t mutrain;


	pthread_cond_t train_arrived;
    pthread_cond_t passenger_seated;


    int passenger_ontrain; // standing passenger in the train
	int waiting_passenger; //waiting passengers on the station
	int empty_seats;       //number of empty seats in the train

};

void station_init(struct station *station);

void station_load_train(struct station *station, int count);

void station_wait_for_train(struct station *station);

void station_on_board(struct station *station);




