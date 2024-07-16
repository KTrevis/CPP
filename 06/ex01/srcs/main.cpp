#include "Data.hpp"
#include "Serializer.hpp"

int	main() {
	Data	data;
	data.setName("Kevin");
	uintptr_t	raw;
	raw = Serializer::serialize(&data);
	Data	*unserialized = Serializer::deserialize(raw);
	std::cout << unserialized->getName() << std::endl;
}
