#include "VerifyGrpcClient.h"
#include "ConfigMgr.h"

RPConPool::RPConPool(size_t poolsize, std::string host, std::string port) :
	poolSize_(poolsize), host_(host), port_(port), b_stop_(false) {
	for (size_t i = 0; i < poolSize_; i++)
	{
		std::shared_ptr<Channel> channel = grpc::CreateChannel(host + ":" + port,
			grpc::InsecureChannelCredentials());
		connections_.push(VarifyService::NewStub(channel));
	}
}

RPConPool::~RPConPool()
{
	std::lock_guard<std::mutex> lock(mutex_);
	Close();
	while (!connections_.empty()) {
		connections_.pop();
	}
}

VerifyGrpcClient::VerifyGrpcClient() {
	auto& gcfgMgr = ConfigMgr::Inst();
	std::string host = gcfgMgr["VarifyServer"]["Host"];
	std::string port = gcfgMgr["VarifyServer"]["Port"];
	pool_.reset(new RPConPool(5, host, port));
}
