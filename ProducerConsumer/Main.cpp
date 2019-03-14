#include <thread>
#include <iostream>

class Game {

	

/* NPC Class which extends Thread and implements an run() method */
		void NPC {

			private Shared s;

			public NPC(Shared s) {
				this.s = s;
			}

			/* demon method runs forever */
			public void run() {
				while (true) {
					System.out.println("NPC..." + this.s.getValue());
					this.s.increment();
				}
			}
		}

		class Player extends Thread {
			private Shared s;

			public Player(Shared s) {
				this.s = s;
			}

			public void run() {
				while (true) {
					System.out.println("Player..." + this.s.getValue());
					this.s.increment();
				}
			}
		}

		//main function
		int main()
		{

		}
		/* Create an instance of Shared Object */
		Shared share = new Shared();

		/* Create a player */
		Player p = new Player(share);

		/* Start player Thread */
		p.start();
		NPC npc = new NPC(share);
		npc.start();
	}
}