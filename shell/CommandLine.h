/*
 * CommandLine.h
 * 
 * This file is part of the "HLSL Translator" (Copyright (c) 2014 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef HTLIB_COMMAND_LINE_H
#define HTLIB_COMMAND_LINE_H


#include <list>
#include <vector>
#include <string>


namespace HTLib
{

namespace Util
{


class CommandLine
{

    public:

        CommandLine() = default;
        CommandLine(const CommandLine&) = default;
        CommandLine& operator = (const CommandLine&) = default;

        CommandLine(int argc, char** argv);
        CommandLine(const std::vector<std::string>& args);

        // Returns the current argument or an empty string if the end has reached.
        std::string Get() const;

        /*
        Returns the current argument and moves on to the next argument or return an empty string if the end has reached.
        If the return value is an empty string, instead an std::invalid_argument exception is thrown.
        */
        std::string Accept();

        /*
        Returns the current argument as boolean (if it is "on" or "off") and moves on to the next argument.
        If the current argument is not "on" or "off" an std::invalid_argument exception is thrown.
        */
        bool AcceptBoolean();

        /*
        Returns the current argument as boolean (if it is "on" or "off") and moves on to the next argument.
        If the current argument is not "on" or "off" the default value is returned.
        */
        bool AcceptBoolean(bool defaultValue);

        // Inserts the specified argument to the current position (this will be the next value returned by the "Get" function).
        void Insert(const std::string& argument);

        // Returns true if the end of the argument list has reached.
        bool ReachedEnd() const;

    private:

        std::list<std::string> args_;

};


} // /namespace Util

} // /namespace HTLib


#endif



// ================================================================================