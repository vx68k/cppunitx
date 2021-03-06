// cppunitx.cpp
// Copyright (C) 2018-2020 Kaz Nishimura
//
// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see <http://www.gnu.org/licenses/>.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <cppunitx/driver>
#include <getopt.h>
#include <sysexits.h>
#include <locale>
#include <memory>
#include <stdexcept>
#include <cstdio>

using std::exception;
using std::fprintf;
using std::locale;
using std::printf;
using std::runtime_error;
using std::shared_ptr;
using namespace cppunitx;

static int process_options(int argc, char **argv,
    const shared_ptr<TestDriver> &driver);
static void print_usage(const char *arg0);

int main(const int argc, char **const argv)
{
    try {
        locale::global(locale(""));
    }
    catch (const runtime_error &e) {
        fprintf(stderr, "note: failed to set the current locale: %s\n", e.what());
    }

    auto &&driver = TestDriver::getInstance();
    int i = process_options(argc, argv, driver);
    while (i != argc) {
        try {
            driver->run(argv[i++]);
        }
        catch (const exception &e) {
            fprintf(stderr, "unhandled exception: %s\n", e.what());
        }
    }

    return 0;
}

int process_options(const int argc, char **const argv,
    [[maybe_unused]] const shared_ptr<TestDriver> &driver)
{
    enum {
        VERSION = -128,
        HELP,
        TEST_NAME,
        LOG_FILE,
        TRS_FILE,
        COLOR_TESTS,
        EXPECT_FAILURE,
        ENABLE_HARD_ERRORS,
        DISABLE_HARD_ERRORS,
    };
    static const struct option options[] = {
        {"test-name", required_argument, nullptr, TEST_NAME},
        {"log-file", required_argument, nullptr, LOG_FILE},
        {"trs-file", required_argument, nullptr, TRS_FILE},
        {"color-tests", optional_argument, nullptr, COLOR_TESTS},
        {"expect-failure", optional_argument, nullptr, EXPECT_FAILURE},
        {"enable-hard-errors", optional_argument, nullptr, ENABLE_HARD_ERRORS},
        {"disable-hard-errors", no_argument, nullptr, DISABLE_HARD_ERRORS},
        {"help", no_argument, nullptr, HELP},
        {"version", no_argument, nullptr, VERSION},
        {}
    };

    int opt = -1;
    do {
        opt = getopt_long(argc, argv, "n:o:", options, nullptr);
        switch (opt) {
        case 'n':
        case TEST_NAME:
            // TODO: Test name.
            break;
        case 'o':
        case LOG_FILE:
            // TODO: Log file.
            break;
        case TRS_FILE:
            // TODO: Trs file.
            break;
        case COLOR_TESTS:
            // TODO: Color tests.
            break;
        case EXPECT_FAILURE:
            // TODO: Expect failure.
            break;
        case ENABLE_HARD_ERRORS:
            // TODO: Enable hard errors.
            break;
        case DISABLE_HARD_ERRORS:
            // TODO: Enable hard errors.
            break;
        case HELP:
            print_usage(argv[0]);
            exit(0);
        case VERSION:
            printf("%s %s %s\n", PACKAGE_NAME, "cppunitx", PACKAGE_VERSION);
            exit(0);
        case '?':
            exit(EX_USAGE);
        }
    }
    while (opt != -1);

    return optind;
}

void print_usage(const char *const arg0)
{
    printf("Usage: %s [OPTION]... [TEST-MODULE]...\n", arg0);
    printf("Run tests in test modules.\n");
    printf("\n");
    printf("      --help            %s\n", "display this help and exit");
    printf("      --version         %s\n", "output version information and exit");
}