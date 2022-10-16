#pragma once

#include "al/Audio/AudioKeeper.h"
#include "al/Effect/EffectKeeper.h"
#include "al/LiveActor/ActorInitInfo.h"
#include "al/LiveActor/ActorPoseKeeper.h"
#include "al/LiveActor/HitSensorKeeper.h"
#include "al/LiveActor/LiveActorFlag.h"
#include "al/LiveActor/SensorMsg.h"
#include "al/LiveActor/SubActorKeeper.h"
#include "al/Nerve/Nerve.h"
#include "sead/math/seadMatrix.h"
#include "types.h"

namespace al {

class LiveActor : public IUseNerve, public IUseEffectKeeper, public IUseAudioKeeper {
public:
    virtual NerveKeeper* getNerveKeeper() const;

    virtual void init(const ActorInitInfo& info);
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void makeActorDead();
    virtual void movement();
    virtual void calcAnim();
    virtual void draw();
    virtual void startClipped();
    virtual void endClipped();
    virtual void attackSensor(HitSensor* me, HitSensor* other);
    virtual bool receiveMsg(SensorMsg msg, HitSensor* other, HitSensor* me);
    virtual sead::Matrix34f* getBaseMtx() const;
    virtual EffectKeeper* getEffectKeeper() const;
    virtual AudioKeeper* getAudioKeeper() const;
    virtual void gap2();
    virtual void gap3();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void updateCollider();

    inline const char* getName() { return mActorName; }

    LiveActor(const char* name);

private:
    int inherit; // ???
    const char* mActorName;

protected:
    ActorPoseKeeperBase* mActorPoseKeeper;
    class ActorExecuteInfo* mActorExecuteInfo;
    class ActorActionKeeper* mActorActionKeeper;
    class Collider* mCollider;
    class CollisionParts* mCollisionParts;
    class ModelKeeper* mModelKeeper;
    NerveKeeper* mNerveKeeper;
    HitSensorKeeper* mHitSensorKeeper;
    EffectKeeper* mEffectKeeper;
    AudioKeeper* mAudioKeeper;
    void* _3C;
    void* _40;
    void* _44;
    class ActorLightKeeper* mActorLightKeeper;
    void* _4C;
    SubActorKeeper* mSubActorKeeper;

private:
    LiveActorFlag mLiveActorFlag;
};

void initNerve(LiveActor* actor, const Nerve* nerve, int step = 0); // may be al::LiveActor::initNerve

static_assert(sizeof(LiveActor) == 0x60, "");

} // namespace al
