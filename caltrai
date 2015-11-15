#include <pthread.h>
#include "caltrain.h"



void
station_init(struct station *station)
{


	pthread_mutex_init(&station->mutrain , NULL);
	pthread_cond_init(&station->train_arrived ,NULL);
	pthread_cond_init(&station->passenger_seated,NULL);


	station->passenger_ontrain=0;
    station->waiting_passenger = 0;
    station->empty_seats = 0;

}

/**When a train arrives in the station and has opened its doors, it invokes this function.
**The function must not return until the train is satisfactorily loaded (all passengers are in their seats,
*and either the train is full or all waiting passengers have boarded).
*Note, that the train must leave the station promptly
*if no passengers are waiting at the station or it has no available free seats.
*/

void
station_load_train(struct station *station, int count)
{
    //returns when the train is full , or there is no passengers left......

    pthread_mutex_lock(&station->mutrain);

    station->empty_seats = count;

    while(station->empty_seats > 0 && station->waiting_passenger > 0){

            pthread_cond_broadcast(&station->train_arrived); //used instead of signal to inform several waiting threads...
            pthread_cond_wait(&station->passenger_seated , &station->mutrain);

    }

    station->empty_seats = 0;
	pthread_mutex_unlock(&station->mutrain);
}


/**When a passenger robot arrives in a station, it first invokes this function.
*This function must not return until a train is in the station and there are enough free seats on
*the train for this passenger to sit down. Once this function returns, the passenger robot will move the
*passenger on board the train and into a seat
*/

void
station_wait_for_train(struct station *station)
{
    //return when the train is in the station, and there are enough seats......
    pthread_mutex_lock(&station->mutrain);
	station->waiting_passenger++;

	while(station->passenger_ontrain == station->empty_seats){
        pthread_cond_wait(&station->train_arrived , &station->mutrain);
	}

	station->passenger_ontrain++;
	station->waiting_passenger--;
	pthread_mutex_unlock(&station->mutrain);
}


/**Once the passenger is seated, it will call this function.
*to let the train know that it’s on board.
*/


void
station_on_board(struct station *station)
{
    //let the train knows that it is on board......
	pthread_mutex_lock(&station->mutrain);
	station->passenger_ontrain--;
	station->empty_seats--;



	if((station->empty_seats == 0) || (station->passenger_ontrain == 0)){
        pthread_cond_signal(&station->passenger_seated);
	}

	pthread_mutex_unlock(&station->mutrain);

}
