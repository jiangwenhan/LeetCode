load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")

all_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

def include_third_party_repositories():
    git_repository(
        name = "com_google_googletest",
        remote = "https://github.com/google/googletest.git",
        tag = "release-1.11.0",
    )

    # gflags
    git_repository(
        name = "com_github_gflags_gflags",
        remote = "https://github.com/gflags/gflags.git",
        tag = "v2.2.2",
    )

    git_repository(
        name = "com_google_absl",
        remote = "https://github.com/abseil/abseil-cpp.git",
        branch = "master",
    )

    git_repository(
        name = "com_google_tcmalloc",
        remote = "https://github.com/google/tcmalloc.git",
        branch = "master",
    )

    http_archive(
        name = "com_github_google_glog",
        sha256 = "21bc744fb7f2fa701ee8db339ded7dce4f975d0d55837a97be7d46e8382dea5a",
        strip_prefix = "glog-0.5.0",
        urls = ["https://github.com/google/glog/archive/v0.5.0.zip"],
    )


