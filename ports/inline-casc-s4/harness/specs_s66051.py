"""specs_s66051.py - cascade s4 batch 66051: 0x421ed0 (run-length packer with literal blocks)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g421ed0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    big = r.random() < 0.1
    n = r.choice([0x7ffe, 0x7fff, 0x8000, 0x8001, 0x8005]) if big else r.choice([0, 1, 3, 4, 5, 9, 20, 40])
    data = bytearray()
    while big and len(data) < n:
        data += bytes([9]) * n
    while len(data) < n:
        if r.random() < 0.4:
            data += bytes([r.choice([0, 1, 7])]) * r.choice([2, 3, 4, 5, 8])
        else:
            data += bytes([r.randrange(1, 255)])
    data = bytes(data[:n])
    src = e.alloc(n + 0x100, 8)
    e.wbytes(src, data + bytes(r.randrange(256) for _ in range(0x20)))
    end = src + n
    cap = r.choice([0, 2, 3, 5, 8, 20, 80]) if not big else 0x300
    out = e.alloc(0x200, 8)
    seqs = [r.choice([0, 1, 2, 5, 40]) for _ in range(16)]
    cnt = {'k': 0}

    def lit(em, rr):                      # 0x4209f0 (src, end) ret 8
        s_, en = em.arg32(0), em.arg32(1)
        k = cnt['k']
        cnt['k'] += 1
        v = min(seqs[min(k, 15)], max(en - s_, 0)) if en > s_ else 0
        em.calllog.append(('lit', em.reg('ecx'), s_ - src, en - src, v))
        em.ret(eax=v, argbytes=8)

    def mc(em, rr):
        d, s_, nn = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memcpy', d - out, s_ - src, nn))
        if nn:
            em.wbytes(d, bytes(em.rbytes(s_, nn)))
        em.ret(eax=d, argbytes=0)
    e.hook(0x4209f0, lit)
    e.hook(0x634d22, mc)
    this = rnd(c, 8)
    return [this, out, out + cap, src, end]


S(0x421ed0, 'GUESS run-length packer with literal blocks', 'thiscall', None, ret='eax', gen=_g421ed0, note='batch66051')
