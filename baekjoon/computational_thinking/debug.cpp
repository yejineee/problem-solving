void FileSystem::debug(Disk *disk) {
    Block block;
    Block inodeBlock;
    Block indirectBlock;

    // Read Superblock
    disk->read(0, block.Data);

    printf("SuperBlock:\n");
    if(block.Super.MagicNumber == MAGIC_NUMBER){
        printf("    magic number is valid\n");
    }
    else{
        printf("+ magic number is invalid\n");
    }
    printf("    %u blocks\n"         , block.Super.Blocks);
    printf("    %u inode blocks\n"   , block.Super.InodeBlocks);
    printf("    %u inodes\n"         , block.Super.Inodes);
    uint32_t numInodeBlocks = block.Super.InodeBlocks;
    for(uint32_t i = 1; i <= numInodeBlocks; i++){
        disk->read(i, inodeBlock.Data);

        for(uint32_t j = 0; j < INODES_PER_BLOCK; j++){
            if(inodeBlock.Inodes[j].Valid != 0){
                printf("Inode %d:\n", (i-1)*INODES_PER_BLOCK + j);
                printf("    size: %d bytes\n", inodeBlock.Inodes[j].Size);
                printf("    direct blocks:");
                for(uint32_t k = 0; k < POINTERS_PER_INODE; k++){
                    if(inodeBlock.Inodes[j].Direct[k] != 0){
                        printf(" %u", inodeBlock.Inodes[j].Direct[k]);
                    }
                }
            printf("\n");
                if(inodeBlock.Inodes[j].Indirect){
                    uint32_t addrIndirect = inodeBlock.Inodes[j].Indirect;
                    printf("    indirect block: %d\n", addrIndirect);
                    disk->read(addrIndirect, indirectBlock.Data);

                    printf("    indirect data blocks:");
                    for(uint32_t k = 0; k < POINTERS_PER_BLOCK; k++){
                        if(indirectBlock.Pointers[k]){
                            printf(" %u", indirectBlock.Pointers[k]);
                        }
                    }
                printf("\n");
                }
            }
        }
    }
    // Read Inode blocks
}