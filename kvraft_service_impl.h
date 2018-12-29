/* kvraft_service_impl.h

 Generated by phxrpc_pb2service from kvraft.proto

*/

#pragma once

#include "phxrpc/network.h"

#include "kvraft.pb.h"
#include "phxrpc_kvraft_service.h"


class KVRaftServerConfig;

typedef struct tagServiceArgs {
    KVRaftServerConfig *config;
    // you can add other arguments here and initiate in main().
} ServiceArgs_t;

class KVRaftServiceImpl : public KVRaftService {
  public:
    KVRaftServiceImpl(ServiceArgs_t &app_args,
            phxrpc::UThreadEpollScheduler *worker_uthread_scheduler);
    virtual ~KVRaftServiceImpl() override;

    virtual int PHXEcho(const google::protobuf::StringValue &req, google::protobuf::StringValue *resp) override;
    virtual int RequestVote(const kvraft::RequestVoteArgs &req, kvraft::RequestVoteReply *resp) override;
    virtual int AppendEntries(const kvraft::AppendEntriesArgs &req, kvraft::AppendEntriesReply *resp) override;
    virtual int Command(const kvraft::KVArgs &req, kvraft::KVReply *resp) override;

  private:
    ServiceArgs_t &args_;
    phxrpc::UThreadEpollScheduler *worker_uthread_scheduler_{nullptr};
};

