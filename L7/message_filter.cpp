#include <vector>
#include "message_simulation.hpp"

static const string words[] = {"cat", "bake", "party", "beer"};

void filter( queue<message> &in, queue<filtered_message> &out) {
	while (true) {
		try {
			message msg = in.dequeue();
			filtered_message filt_msg = filtered_message();
			string filtered_text = msg.text;

			for (size_t i=0; i < ( sizeof(words)/sizeof(words[0])); i++) {
				size_t index = 0;
				while (true) {
					index = filtered_text.find(words[i], index);

					if (index == std::string::npos) {
						break;
					}

					filt_msg.ok = false;
					filtered_text.replace( index, words[i].size(), string(words[i].size(), '*') );
				}
			}
			filt_msg.text = filtered_text;
			out.enqueue(filt_msg);
		}
		catch (queue_empty_exception) {
			break;
		}
	}
}

int main(void) {
	
	simulation sim = simulation();
	sim.run();

	return EXIT_SUCCESS;
}
