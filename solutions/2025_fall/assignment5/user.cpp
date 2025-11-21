#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

std::ostream& operator<< (std::ostream& os, const User & other)
{
  os << "User(name=" << other.get_name() << ", friends=[";
  for (size_t i = 0; i < other._size; ++i) {
    os << other._friends[i];
    if (i + 1 < other._size) {
      os << ", ";
    }
  }
  os << "])";

  return os;
}

User& User::operator+=(User & rhs)
{
  this->add_friend(rhs.get_name());
  rhs.add_friend(this->get_name());

  return *this;
}

bool User::operator<(const User & rhs) const
{
  char lhs_c = std::toupper(this->_name[0]);
  char rhs_c = std::toupper(rhs._name[0]);
  return lhs_c < rhs_c ? true : false;
}

/**
 * SMF
 */
User::User(const User& other)
  : _name(other._name)
  , _friends(other._capacity ? new std::string[other._capacity] : nullptr)
  , _size(other._size)
  , _capacity(other._capacity)
{
  std::copy(other._friends, other._friends + other._size, this->_friends);
}

User& User::operator=(const User& other)
{
  // Check for self assignment
  if (this == &other) return *this;

  delete[] this->_friends;

  // Copy content
  this->_name = other._name;
  this->_friends = new std::string[other._capacity];
  std::copy(other._friends, other._friends + other._size, this->_friends);
  this->_size = other._size;
  this->_capacity = other._capacity;

  return *this;
}

/**
 * Destructor
 */
 User::~User()
{
  delete[] this->_friends;
}