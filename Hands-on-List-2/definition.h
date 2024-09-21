typedef struct ticketDatabase {
	int ticket_num;
} TicketDatabase;


typedef union semun{
    int val;
    struct semid_ds *buf;
    int key, semid;
} SemUnion;
