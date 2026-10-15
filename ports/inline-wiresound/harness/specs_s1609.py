"""specs_s1609.py - soundtimers batch 1609: ZIKLNKOBJ::PlaySoundSFX and PlaySoundSpeech.
AddSound3d is re-hooked with a Python recorder that logs the matrix and position CONTENTS (the speech path passes
stack buffers, whose addresses differ between the runs)."""
import struct
from pilot import S
from sthelp import rnd, stub, Seq, world, hook, HOOKED


def _add3d(c, seq, ret):
    log = c.emu.alloc(4 + 4 * 16, 4)

    def h(e, r):
        sp = e.reg('esp')
        mat, pos = e.r32(sp + 4), e.r32(sp + 8)
        e.wbytes(log + 4, e.rbytes(mat, 0x24))
        e.wbytes(log + 0x28, e.rbytes(pos, 12))
        for i in range(4):
            e.w32(log + 0x34 + 4 * i, e.r32(sp + 12 + 4 * i))
        e.w32(log, e.r32(log) + 1)
        e.w32(seq.addr, e.r32(seq.addr) + 1)
        e.ret(eax=ret, argbytes=0x18)
    c.emu.unhook(0x43ec00)
    c.emu.hook(0x43ec00, h)
    HOOKED.add(0x43ec00)


def _fill(c, seq):
    r = c.rng
    vals = [r.uniform(-100, 100) for _ in range(12)]

    def h(e, rr):
        sp = e.reg('esp')
        mat, pos = e.r32(sp + 4), e.r32(sp + 8)
        for i in range(9):
            e.mu.mem_write(mat + 4 * i, struct.pack('<f', vals[i]))
        for i in range(3):
            e.mu.mem_write(pos + 4 * i, struct.pack('<f', vals[9 + i]))
        e.w32(seq.addr, e.r32(seq.addr) + 1)
        e.ret(eax=0x1234, argbytes=8)
    return c.emu.stub_fn('GetHeadMatrix', h)


def _sfx(c):
    seq = Seq(c)
    me, hc, hn = world(c, seq)
    return [me, c.rng.getrandbits(32)]


S(0x467230, 'ZIKLNKOBJ::PlaySoundSFX', 'thiscall', None, ret='eax', gen=_sfx, note='batch1609')


def _speech(c):
    seq = Seq(c)
    r = c.rng
    me, hc, hn = world(c, seq, slots={0x3a0: _fill(c, seq), 0x390: stub(c, seq, 1)},
                       dll_slots={0x70: stub(c, seq, 1, ret=(r.getrandbits(24) << 8) | r.choice([0, 1]))})
    _add3d(c, seq, hn)
    hook(c, seq, 0x44b610, 0)
    hook(c, seq, 0x44b740, 1, this=False, pop=False)
    k = r.random()
    c.emu.w32(me + 0x153, hc if k < 0.5 else (0 if k < 0.8 else r.getrandbits(32)))
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x467260, 'ZIKLNKOBJ::PlaySoundSpeech', 'thiscall', None, ret='eax', gen=_speech, note='batch1609')
