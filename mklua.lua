
function main()
    local opt = arg[1]
    cmd = ""
    IS_CMD_EXECUTED = true
    if opt == "h" then
        print("-- help")
        print("gen")
        print("clean")
        print("clean-exe")
        print("build")
        print("see-build")




        IS_CMD_EXECUTED = false
    -- construct cmake build file
    -- mklu gen
    elseif opt == "gen" then
        print("-- Generating CMake first build")
        cmd = string.format("%s %s %s %s %s", "cmake", "-S", ".", "-B", "./build") 
        


    -- clean cmake build file
    -- mklu clean
    elseif opt == "clean" then
        print("-- Clean CMAKE-BUILD-DIR-INSIDE")
        cmd = string.format("%s %s %s", "rm", "build/*", "-r")
    elseif opt == "clean-exe"then
        print("-- Clean CMAKE-EXE-FILE")
        cmd = string.format("%s %s %s", "rm", "build/*", "-r")

    elseif opt == "see-build" then
        print("# ls build/")
        cmd = string.format("%s %s", "exa", "build/")
    elseif opt == "build" then
        print("# build CMakeCache")
        cmd = string.format("%s %s %s", "cmake", "--build", "build/")
    elseif opt == "check-out" then
        cmd = string.format("%s %s", "file", "./debug-linux-x86-64b/isolate.out")
    elseif opt == "run" then
        cmd = string.format("%s", "./debug-linux-x86-64b/isolate.out")
    end

    -- next part
    
    if IS_CMD_EXECUTED then
        -- forming CMDs
        cmd = string.format("fish --command \"%s\"", cmd)
    end
    print(cmd)
    print()
    os.execute(cmd)

end

main()
