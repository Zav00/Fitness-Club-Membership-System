#ifndef FITNESS_CLUB_MEMBERSHIP_SYSTEM_MEMBER_H
#define FITNESS_CLUB_MEMBERSHIP_SYSTEM_MEMBER_H
#include <string>
class Member {
private:
    std::string name;
    std::string contactInfo;
    std::string membershipLevel;
    int remainingFitnessEntries;
    int remainingMassages;
    int remainingPoolEntries;
    time_t membershipStartDate;
public:
    Member(const std::string &name, const std::string &contactInfo, const std::string &membershipLevel)
            : name(name), contactInfo(contactInfo), membershipLevel(membershipLevel),
              membershipStartDate(time(nullptr)) {
        if (membershipLevel == "standard") {
            remainingFitnessEntries = 12;
            remainingMassages = 1;
            remainingPoolEntries = 6;
        } else if (membershipLevel == "premium") {
            remainingFitnessEntries = 24;
            remainingMassages = 2;
            remainingPoolEntries = 12;
        } else if (membershipLevel == "all included") {
            remainingFitnessEntries = -1;
            remainingMassages = -1;
            remainingPoolEntries = -1;
        }
    }

    std::string getName() const {
        return name;
    }

    std::string getMembershipLevel() const {
        return membershipLevel;
    }

    const std::string &getContactInfo() const {
        return contactInfo;
    }

    int getRemainingFitnessEntries() const {
        return remainingFitnessEntries;
    }

    int getRemainingMassages() const {
        return remainingMassages;
    }

    int getRemainingPoolEntries() const {
        return remainingPoolEntries;
    }

    void updateRemainingFitnessEntries(int count) {
        remainingFitnessEntries -= count;
    }

    void updateRemainingMassages(int count) {
        remainingMassages -= count;
    }

    void updateRemainingPoolEntries(int count) {
        remainingPoolEntries -= count;
    }

    time_t getMembershipStartDate() const {
        return membershipStartDate;
    }

    time_t getMembershipEndDate() const {
        time_t endDate = membershipStartDate + 30 * 24 * 60 * 60;
        return endDate;
    }
};
#endif //FITNESS_CLUB_MEMBERSHIP_SYSTEM_MEMBER_H
