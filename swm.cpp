#include <iostream>
#include <string>
#include <map>
#include <list>
#include <iomanip>

using namespace std;

struct Review {
    int customer_id;
    float food_rating;
    float service_rating;
    float environment_rating;
    string timestamp;
    int version;

    Review(int id, float food, float service, float environment, const string &time, int ver) :
            customer_id(id), food_rating(food), service_rating(service), environment_rating(environment),
            timestamp(time), version(ver) {}
};

auto printRating = [](float rating) {
    if (rating == static_cast<int>(rating)) cout << static_cast<int>(rating);
    else cout << fixed << setprecision(1) << rating;
};

class CustomerReviewSystem {
private:
    map<int, list<Review>> reviews;

public:
    void insertReview(int customer_id, float food_rating, float service_rating, float environment_rating,
                      const string &timestamp) {
        int version = 1;
        Review new_review(customer_id, food_rating, service_rating, environment_rating, timestamp, version);
        reviews[customer_id].push_front(new_review);
        cout << "Review inserted successfully" << endl;
    }

    void modifyReview(int customer_id, const string &dimension, float new_rating, const string &timestamp) {
        if (reviews.find(customer_id) == reviews.end()) {
            cout << "Customer ID not found, modification failed" << endl;
            return;
        }

        Review last_review = reviews[customer_id].front();
        int new_version = last_review.version + 1;

        if (dimension == "food") {
            last_review.food_rating = new_rating;
        } else if (dimension == "service") {
            last_review.service_rating = new_rating;
        } else if (dimension == "environment") {
            last_review.environment_rating = new_rating;
        }
        last_review.timestamp = timestamp;
        last_review.version = new_version;
        reviews[customer_id].push_front(last_review);

        cout << "Modification successful" << endl;
    }

    void deleteReview(int customer_id) {
        if (reviews.find(customer_id) == reviews.end()) {
            cout << "Customer ID not found, deletion failed" << endl;
            return;
        }

        reviews.erase(customer_id);
        cout << "Deletion successful" << endl;
    }

    void showHistory(int customer_id, const string &dimension = "") {
        list<Review> &customer_reviews = reviews[customer_id];
        cout << "History:" << endl;
        list<Review> all_reviews;
        for (auto &entry: reviews) all_reviews.push_back(entry.second.front());
        if (dimension == "food") {
            for (const auto &review: all_reviews) {
                cout << "Customer ID " << review.customer_id << " Food Rating ";
                printRating(review.food_rating);
                cout << " Timestamp " << review.timestamp << endl;
            }
        } else if (dimension == "service") {
            for (const auto &review: all_reviews) {
                cout << "Customer ID " << review.customer_id << " Service Rating ";
                printRating(review.service_rating);
                cout << " Timestamp " << review.timestamp << endl;
            }
        } else if (dimension == "environment") {
            for (const auto &review: all_reviews) {
                cout << "Customer ID " << review.customer_id << " Environment Rating ";
                printRating(review.environment_rating);
                cout << " Timestamp " << review.timestamp << endl;
            }
        } else
            for (const auto &review: customer_reviews) {
                if (dimension.empty()) {
                    cout << "Version " << review.version << ": ";
                    cout << "Food Rating ";
                    printRating(review.food_rating);
                    cout << " Service Rating ";
                    printRating(review.service_rating);
                    cout << " Environment Rating ";
                    printRating(review.environment_rating);
                    cout << " Timestamp " << review.timestamp << endl;
                }
            }
    }

    void displayReviews(const string &dimension = "") {
        list<Review> all_reviews;

        for (auto &entry: reviews) all_reviews.push_back(entry.second.front());

        all_reviews.sort([](const Review &a, const Review &b) { return a.timestamp > b.timestamp; });
        if (dimension == "food") {
            for (const auto &review: all_reviews) {
                cout << "Customer ID " << review.customer_id << " Food Rating ";
                printRating(review.food_rating);
                cout << " Timestamp " << review.timestamp << endl;
            }
        } else if (dimension == "service") {
            for (const auto &review: all_reviews) {
                cout << "Customer ID " << review.customer_id << " Service Rating ";
                printRating(review.service_rating);
                cout << " Timestamp " << review.timestamp << endl;
            }
        } else if (dimension == "environment") {
            for (const auto &review: all_reviews) {
                cout << "Customer ID " << review.customer_id << " Environment Rating ";
                printRating(review.environment_rating);
                cout << " Timestamp " << review.timestamp << endl;
            }
        } else {
            for (const auto &review: all_reviews) {
                cout << "Customer ID " << review.customer_id << " Food Rating ";
                printRating(review.food_rating);
                cout << " Service Rating ";
                printRating(review.service_rating);
                cout << " Environment Rating ";
                printRating(review.environment_rating);
                cout << " Timestamp " << review.timestamp << endl;
            }
        }
    }

    void rangeQuery(float food_lower, float food_upper, float service_lower, float service_upper,
                    float environment_lower, float environment_upper) {
        for (auto &entry: reviews) {
            Review &review = entry.second.front();
            if (review.food_rating >= food_lower && review.food_rating <= food_upper &&
                review.service_rating >= service_lower && review.service_rating <= service_upper &&
                review.environment_rating >= environment_lower && review.environment_rating <= environment_upper) {
                cout << "Customer ID " << review.customer_id << " Food Rating ";
                printRating(review.food_rating);
                cout << " Service Rating ";
                printRating(review.service_rating);
                cout << " Environment Rating ";
                printRating(review.environment_rating);
                cout << " Timestamp " << review.timestamp << endl;
            }
        }
    }
};

int main() {
    CustomerReviewSystem system;
    int n;
    cin >> n;

    string command;
    while (n--) {
        cin >> command;

        if (command == "insert") {
            int customer_id;
            float food_rating, service_rating, environment_rating;
            string timestamp;
            cin >> customer_id >> food_rating >> service_rating >> environment_rating;
            cin.ignore();
            getline(cin, timestamp);
            system.insertReview(customer_id, food_rating, service_rating, environment_rating, timestamp);
        } else if (command == "modify") {
            int customer_id;
            string dimension;
            float new_rating;
            string timestamp;
            cin >> customer_id >> dimension >> new_rating;
            cin.ignore();
            getline(cin, timestamp);
            system.modifyReview(customer_id, dimension, new_rating, timestamp);
        } else if (command == "delete") {
            int customer_id;
            cin >> customer_id;
            system.deleteReview(customer_id);
        } else if (command == "history") {
            int customer_id;
            string dimension;
            cin >> customer_id;
            if (cin.peek() != '\n') {
                cin >> dimension;
            }
            system.showHistory(customer_id, dimension);
        } else if (command == "display") {
            string dimension;
            if (cin.peek() != '\n') {
                cin >> dimension;
            }
            system.displayReviews(dimension);
        } else if (command == "range_query") {
            float food_lower, food_upper, service_lower, service_upper, environment_lower, environment_upper;
            cin >> food_lower >> food_upper >> service_lower >> service_upper >> environment_lower >> environment_upper;
            system.rangeQuery(food_lower, food_upper, service_lower, service_upper, environment_lower,
                              environment_upper);
        }
    }
}
