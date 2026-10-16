"""specs_s66093.py - cascade s4 batch 66093: 0x4248e0 (RDTSC reader). An instruction hook pins the emulator's time stamp counter to a per-case value so both executions read the same one."""
from pilot import S
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_EIP

VAL = {'lo': 0, 'hi': 0}
_hooked = set()


def _on_rdtsc(uc, addr, size, ud):      # replace the 2-byte RDTSC (0f 31) by a fixed EDX:EAX
    uc.reg_write(UC_X86_REG_EAX, VAL['lo'])
    uc.reg_write(UC_X86_REG_EDX, VAL['hi'])
    uc.reg_write(UC_X86_REG_EIP, addr + 2)


def _g4248e0(c):
    r = c.rng
    mu = c.emu.mu
    if id(mu) not in _hooked:
        _hooked.add(id(mu))
        mine = c.emu.decomp[0x4248e0]
        for a in (0x4248ea, mine + 0xa):          # the original's RDTSC and the port's (same prologue, same offset)
            mu.hook_add(UC_HOOK_CODE, _on_rdtsc, None, a, a)
    VAL['lo'] = r.choice([0, 1, 0xffffffff, r.getrandbits(32)])
    VAL['hi'] = r.choice([0, 1, 0x80000000, r.getrandbits(32)])
    return []


S(0x4248e0, 'GUESS read the time stamp counter', 'cdecl', None, ret='eax:edx', gen=_g4248e0, note='batch66093')
